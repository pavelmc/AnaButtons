Analog Buttons for Arduino (AnaButtons)
=======================================

Manage up to six buttons over just one analog pin, that's my goal.

This library will allow you to have from 1 to 6 buttons over a single analog pin in your Arduino projects; all you need is the push buttons (obviously) a few resistors with a peculiar relationship you will see later and a few capacitors.


How it works?
=============

By reading the analog value every time and averaging the difference over time, to know if the variation drift towards zero (aka it's stable to read) and then compare the actual value against the predefined ranges to emit a status and using a timer to avoid repeated emits.

Just follow the instructions in the INSTALL.txt file and start the Arduino IDE, then go to examples and search for the AnaButtons then the only example to check how it works.


What about the circuit to make it works?
========================================

Find 5 resistors that are half of each other and add one more for the highest value, with that you will be in ball park values of what is programed in the library.

For example I have tested with this series of resistors (others combinations are possible):

 * 10k, 4.7k, 2.2k, 1k, 470 + 10k
 * 3.3k, 1.2k, 680, 330, 150 + 3.3k
 * 2,2k, 1k, 510, 220, 100 + 2,2k

The ranges programed has computed a variation of about 20% of tolerance on the resistors and that's allow for some room, for example in the previous example on the last series I can change the 510 by a 470 ohms resistor and it still works.

You have to take into account that for smooth work of the library you have to put a capacitor of about 10 to 100 nF in parallel with each push button to avoid noise.

About the schematics I can offer this files made with [Fritzing](http://www.fritzing.org):

- Whole Fritzing file: sketch.fzz (the PCB view is an autorouted one, not ready for production)
- Arduino wiring diagram: sketch_bb.png
- Schematic diagram: sketch_esquema.png


What if I only need 4 and no six buttons?
=========================================

Just wire the buttons you need, the others will be included in the code but as they are not wired they will never trigger any action (see the below note).

Keep in mind that for stability issues you must always keep the lower and higher ones (marked SW1 and SW6 in the diagrams)

Note: If you have a flash space problem the I will recommend that you modify the library to only manage the buttons you need and this will save you a few bits of flash space.


Author & contributors
=====================

The only author is Pavel Milanes CO7WT, reachable at pavelmc@gmail.com

Until now I have no contributions.


Where to download the latest version?
======================================

Always download the latest version from the [github repository](https://github.com/pavelmc/AnaButtons/)


If you need to give thanks...
=============================

Please take a look at the Donations and Funding file to keep me sharing my work with you.
