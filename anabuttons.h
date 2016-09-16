/*************************************************************************
 *
 * Analog Buttons library, by Pavel Milanes CO7WT, pavelmc@gmail.com
 *
 * The goal to this lib is to handle up to 6 analog buttons in just one
 * analog pin, see sketch_bb.png to see a circuit example
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * **************************************************************************/

#ifndef anabuttons_h
#define anabuttons_h

#include "Arduino.h"

/*
 * Define the possible states to give away
 *
 */
// no change or unstable
#define NOBUTTON    0
// button pressed and stable
#define ABUTTON1_PRESS      1
#define ABUTTON2_PRESS      2
#define ABUTTON3_PRESS      3
#define ABUTTON4_PRESS      4
#define ABUTTON5_PRESS      5
#define ABUTTON6_PRESS      6
// the threshold to know the reading is stable (+/- ~0)
#define THRESHOLD           2


/*
 * The class...
 */
class AnaButtons {
 public:
    // Instantiate, assume the default millis
    AnaButtons(char);
    // Get the status of the buttons
    char getStatus();

 private:
    word lastValue              = 0;
    char lastPressed            = 0;
    word move[3]                = {0, 5, 50};  // init as a raising value
    int amove                   = 0;
    word intervalMillis         = 250;
    unsigned long lastMillis    = 0;
    char pin;
    char debounce(char);
    word ave(word);
};

#endif
