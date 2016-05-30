#!/usr/bin/env python

'''ex3-RPPPSOC.py

Code to toggle a single line on the RPPSOC card for a Raspberry Pi Model B Plus.

This code must be run as Superuser on the Raspberry Pi.

============
Dependencies
============

Need to: 

* sudo apt-get install python-dev
* sudo apt-get install python-pip python2.7-dev
* sudo apt-get install python-rpi.gpio
* sudo pip install flask

====
Code
====
'''

import RPi.GPIO as GPIO
import os
import time

# Assign all of the GPIO lines (by board pin numbering) to their corresponding jacks 
# on the GVS card.

IO18 = 18

def blinkLED(channel):
	'''Function to blink an LED attached to an output channel
	Drives line high for a short time and then drives it low.
	The high level output turns on the LED.
	'''
	GPIO.output(channel, 1)
	time.sleep(0.5)
	GPIO.output(channel, 0)
	time.sleep(0.5)
	
GPIO.setmode(GPIO.BCM)	# setup GPIO using Board numbering

# Set the pin to output

GPIO.setup(IO18, GPIO.OUT)

# Blink all of the LEDs one at a time forever
# CTRL-C to exit which is not a particularly elegant exit strategy, but this is a demo program

while 1:
	blinkLED(IO18)
