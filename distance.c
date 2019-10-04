#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <sys/time.h>

#define SPEED_OF_SOUND_CM_PER_MICROSECOND 0.0343

int main(void) {
    wiringPiSetup();

    // Read configured pins from environment, with fallbacks.
    int echo = getenv("ECHO") ? atoi(getenv("ECHO")) : 0;          // BCM 17
    int trigger = getenv("TRIGGER") ? atoi(getenv("TRIGGER")) : 1; // BCM 18

    // Set pin modes.
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    // Reset trigger and wait for sensor to settle.
    digitalWrite(trigger, LOW);
    usleep(2);

    // Signal intent to measure via 10μs pulse to sensor.
    digitalWrite(trigger, HIGH);
    usleep(10);
    digitalWrite(trigger, LOW);

    // Measure elapsed time from start to end of HIGH signal received.
    struct timeval start, end;
    gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);

    while (digitalRead(echo) == 0) {
        gettimeofday(&start, NULL);
    }

    while (digitalRead(echo) == 1) {
        gettimeofday(&end, NULL);
    }

    suseconds_t elapsed = end.tv_usec - start.tv_usec;

    // Compute distance as one-way (half) of the time elapsed relative speed of
    // sound.
    double distance_cm = elapsed * SPEED_OF_SOUND_CM_PER_MICROSECOND / 2;

    // Output distance.
    printf("%.3f", distance_cm);

    return 0;
}
