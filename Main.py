#!/usr/bin/python
#Geoff Spielman
#April 22, 2016
import sys
import time
import RPi.GPIO as GPIO
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)


##for i in range(1, 11):
##    print ("Enter something")
##    input = sys.stdin.readline().strip()
##    print ('For input %d you entered: %s' %(i, input))


print ('How many times should LED blink?')
input = sys.stdin.readline().strip()
BA = bytearray()
BA.extend(map(ord, input))

print (BA)

ser.write(BA)

##for i in range (1, input + 1):
##    GPIO.output(18, 1)
##    time.sleep(0.5)
##    GPIO.output(18, 0)
##    time.sleep(0.5)

GPIO.cleanup()
