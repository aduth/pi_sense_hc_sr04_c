# HC-SR04 Distance

Simple distance measurement program for the [HC-SR04 Ultrasonic Distance Sensor](https://www.adafruit.com/product/4007) on Raspberry Pi, written in C. Outputs a float value to standard output representing the measured distance in centimeters, to three decimal places.

## Requirements

This program is targeted for use on a Raspberry Pi device, presumably running [Raspbian](https://www.raspberrypi.org/downloads/raspbian/) (or Raspbian Lite).

This program uses the [WiringPi library](http://wiringpi.com/) for GPIO interfacing. This is installed by default on Raspbian. If you're using Raspbian Lite, you will need to [install it manually](http://wiringpi.com/download-and-install/):

```bash
sudo apt-get install wiringpi
```

## Installation

Clone the repository, then build the program via the included Makefile:

```
git clone https://github.com/aduth/pi_sense_hc_sr04_c.git
cd pi_sense_hc_sr04_c
make
```

## Usage

Assuming you are in the project directory and have compiled the program, simply run the executable:

```
./distance
```

By default, the program assumes you have assigned the sensor's "Echo" as BCM 17 (WiringPi 0) and "Trigger" as BCM 18 (WiringPi 1).

For custom configurations, refer to the [GPIO Pinout guide for Raspberry Pi](https://pinout.xyz/), specifically the [WiringPi pin numbering](https://pinout.xyz/pinout/wiringpi). Assign these values as the ECHO and TRIGGER environment variables respectively:

```
ECHO=0 TRIGGER=1 ./distance
```

## License

Copyright 2019 Andrew Duthie

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.