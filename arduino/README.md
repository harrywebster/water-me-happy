# Arduino apps

## Module 1

We need an app to run on the arduino to verify that the water pump, battery pack, switching board, wiring and moisture sensor is all working correctly. If they don't then hours or days can be lost later trying to debug.

If in the future something isn't working quite as you expect it to, come back to this module to ensure your problem is not hardware related.

## Module 2

Adding a second pump and moisture sensor and check them independantly.


## Module 3

Added functionality to "dose" water, rather than just turning on the pump it now turns on the pump for a given number of seconds before turning off. It will then not attempt to re-water (aka re-dose) the plant for 10 minutes.

## Module 4

Break out a single LARGE .ino file for the arduino board into multiple files sorted by a prefix number. To combine these into a single file for compiling on the Arduino follow the steps in `HOWTO export a multi file module` below.

## HOWTO export a multi file module

Change directory into `./main/arduino` then run the following to build the docker image:

```
docker build -t flatten ./
docker run -e PROJECT=4-break-out-files flatten:latest
```

... obviously changing `4-break-out-files` to the name of the directory that you wish to concatenate together into a single "flat" file.
