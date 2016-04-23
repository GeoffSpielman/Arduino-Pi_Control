#!/usr/bin/python
import sys
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)


##for i in range(1, 11):
##    print ("Enter something")
##    input = sys.stdin.readline().strip()
##    print ('For input %d you entered: %s' %(i, input))


print ('How many times should LED blink?')
input = int(sys.stdin.readline().strip())
for i in range (1, input + 1):
    GPIO.output(18, 1)
    time.sleep(0.5)
    GPIO.output(18, 0)
    time.sleep(0.5)

print ('finished')
GPIO.cleanup()
