# xmas_tree

An introduction-to-electronics project for kids around 10.


## Assembly

Assemble according to the schematic.

Soldering should be easy - except for the USB connector and perhaps the micro.

For the USB connector:
1. Put the connector in place, and hold it while flipping the PCB over.
2. Solder one of the ground pins that comes through the PCB to hold in place
3. Double check that it's in the right spot
4. Solder the remaining ground pins from the bottom.
5. Solder the signal pins using as little solder as you can.
6. If you bridge two pins, then you can use solder wick or remove with the soldering iron

To remove solder with the soldering iron, clean the tip with a wet sponge, apply the tip to the excess solder
and it will pick up a small amount.  Repeat cleaning and appplying tip to excess solder many times - say 10.

For the micro:
1. Ensure the right way around - there's a dot marking pin 1 - should go near the "U1" label.
2. Put in place and solder just one pin to hold it
3. Ensure in place, melt the soldered pin to adjust as necessary
4. Solder another pin on the far side
5. Ensure placement is still good.
6. Solder remaining pins
7. If you bridge two pins, then you can use solder wick or remove with the soldering iron

To remove solder with the soldering iron, clean the tip with a wet sponge, apply the tip to the excess solder
and it will pick up a small amount.  Repeat cleaning and appplying tip to excess solder many times - say 10.

For all the surface mount parts:
1. Apply solder to one pad
2. Position the part and melt the solder to join the part
3. Solder the remaining pad

For the LEDs (colour and front/back is at the user's discretion):
1. Short legs go near the flat side of the circle on the PCB outline - they all face the same direction
2. Put one leg in each hole and push down fairly close to the PCB.
3. Spread the legs slightly to hold in place
4. Solder both legs
5. Cut off excess with wire cutters


## Compiling

Under linux, avr-gcc is required.  Compile by typing

make

## Programming

sudo dfu-programmer atmega16u2 erase

sudo dfu-programmer atmega16u2 flash main.hex 

sudo dfu-programmer atmega16u2 start

To re-enter bootloader programming over USB, short (connect) between R21 and the nearby battery holder
and press the reset button.  A paperclip can be used.  When done right, LED21 will be on during the reset.


## Known Issues

Running from batteries will require programming the fuses - which can't be done over USB.  To be completed...
