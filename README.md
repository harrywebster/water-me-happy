# water-me-happy

## Introduction

After deciding to start a veg-patch in my garden with my kids, i thought, being a programmer 'n all, i should geek this up a bit.

Using a Raspberry Pi, Arduino, pumps, tubing, sensors etc we will build a watering system that will be controled via a "game".

## Prerequsites for proof of concept

* Raspberry Pi 4B
* Mega 2560 prototyping board
* JT-DC3W x 4 - HYS Water Pomp DC 3V 4.5V Submersible
* 1 meter of tubing
* Soil moisture sensor x 4

## Modules

### Module 0 - Get to know your plants

1. For each plant we need to know:
  1. How often does it need watering (in hours)
  2. How much (in ML) water is considered a "dose"
2. Find a place where you can put your plants in the house and build the irrigation system.

### Module 1 - Hello world

### Module 2 - Calibrating and planning

We need to know the flow rate, for each plant the flow rate will be different, depending on a number of factors:

* How far the water needs to travel
* If it need to fight gravity
