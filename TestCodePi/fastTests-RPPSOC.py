#!/usr/bin/env python

'''fastTests-RPPSOC.py

Code to daisy chain test the I/O lines as a daisy chain on the RPPSOC card.

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

UART_TX = 14
UART_RX = 15
SPI__MOSI = 10
SPI_MISO = 9
SPI_SCLK = 11
SPI_CE0 = 8
SPI_CE1 = 7
IO4 = 4
IO5 = 5
IO6 = 6
IO12 = 12
IO13 = 13
IO16 = 16
IO17 = 17
IO18 = 18
IO19 = 19
IO20 = 20
IO21 = 21
IO25 = 25
IO26 = 26
IO27 = 27

# Rsserved IO pins due to the programming interface
#IO22 = 22
#IO23 = 23
#IO24 = 24

def testPair(ch2,ch1):
	'''Function to test I/O Pair.
	Sets one pin to be an output and the other pin to be an input. 
	Set the output high and check the input matches.
	Set the output low and check the output matches.
	'''
	GPIO.setup(ch1, GPIO.IN)
	GPIO.setup(ch2, GPIO.OUT)
	GPIO.output(ch2, 1)
	time.sleep(0.0001)
	if GPIO.input(ch1) != 1:
		print 'Error reading high on channels', ch1, ch2
		GPIO.setup(ch2, GPIO.IN)
		return False
	GPIO.output(ch2, 0)
	time.sleep(0.0001)
	if GPIO.input(ch1) != 0:
		print 'Error reading low on channels', ch1, ch2
		GPIO.setup(ch2, GPIO.IN)
		return False
	GPIO.setup(ch2, GPIO.IN)
	return True
	
def daisyTests():
	if testPair(IO17,IO12) == False:
		print '17-12 Test failed'
		return False
	if testPair(IO18,IO13) == False:
		print '18-13 Test failed'
		return False
	if testPair(IO27,IO19) == False:
		print '27-19 Test failed'
		return False
	if testPair(IO25,IO16) == False:
		print '22-16 Test failed'
		return False
	if testPair(IO5,IO26) == False:
		print '5-26 Test failed'
		return False
	if testPair(IO6,IO20) == False:
		print '6-20 Test failed'
		return False
	if testPair(IO21,SPI_MISO) == False:
		print 'SPI_MISO-IO21 Test failed'
		return False
	if testPair(SPI_SCLK,UART_TX) == False:
		print 'SPI_SCLK-UART_TX Test failed'
		return False
	if testPair(SPI_CE0,UART_RX) == False:
		print 'SPI_CE0-UART_RX Test failed'
		return False
	if testPair(SPI_CE1,SPI__MOSI) == False:
		print 'SPI_CE1-SPI__MOSI Test failed'
		return False
	return True
	
GPIO.setmode(GPIO.BCM)	# setup GPIO using Board numbering

# CTRL-C to exit which is not a particularly elegant exit strategy, but this is a demo program

daisyTestCount = 1
while 1:
	if daisyTests() == True:
#		print 'Daisy test passed',daisyTestCount
		daisyTestCount += 1
	else:
		print 'Daisy test failed'
		break;
	if daisyTestCount > 100:
		print 'Passed 100 loop test'
		break;
