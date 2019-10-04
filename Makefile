CC=gcc
CFLAGS=-Wall
LIBS=-lwiringPi
EXECUTABLE=distance

.DEFAULT_GOAL := distance

distance: distance.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) distance.c $(LIBS)
