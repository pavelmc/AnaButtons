// Please read anabuttons.h for information about the license and author

#include "Arduino.h"
#include "anabuttons.h"


/*
 * Constructor, just pass the analog pin to read from and make the first read
 * the default interval in millis is assumed
 */
AnaButtons::AnaButtons(char _pin) {
    pin = _pin;

    // set the reference to the default Vcc of the device
    analogReference(DEFAULT);

    // set this pin as input & read a value from it
    pinMode(pin, INPUT);
    lastValue = analogRead(pin);
}


/*
 * Average the delta in the movement
 */
word AnaButtons::ave(word diff) {
    // shift the array
    move[0] = move[1];
    move[1] = move[2];
    move[2] = diff;

    // average & return it
    return (move[0] + move[1] + move[2])/3;
}


/*
 * Debounce the output, to avoid emit multiple duplicated values
 */
char AnaButtons::debounce(char btn) {
    // reset the lastMillis to debounce
    lastMillis = millis();
    lastPressed = btn;
    return btn;
}

/*
 * Get the button's status.
 */
char AnaButtons::getStatus() {
    // if we have raised one status and the interval is not over just ignore
    word tdiff = millis() - lastMillis;
    if ((lastPressed != NOBUTTON) & (tdiff < intervalMillis)) {
        return NOBUTTON;
    }

    // read the analog pin
    word value = analogRead(pin);

    // get the delta averaged
    amove = lastValue;
    amove -= value;
    amove = ave(amove);

    // is the value stable?
    if ((amove < -THRESHOLD) & (amove > THRESHOLD)) {
        // no, it's not
        lastValue = value;

        // just return no change
        return debounce(NOBUTTON);
    } else {
        // it's stable, parse the defined values
        if ((value > 430) & (value < 674))
            return debounce(ABUTTON1_PRESS);

        if ((value > 256) & (value < 421))
            return debounce(ABUTTON2_PRESS);

        if ((value > 140) & (value < 237))
            return debounce(ABUTTON3_PRESS);

        if ((value > 75) & (value < 122))
            return debounce(ABUTTON4_PRESS);

        if ((value > 36) & (value < 60))
            return debounce(ABUTTON5_PRESS);

        if (value < 10)
            return debounce(ABUTTON6_PRESS);

        // if you get here, you are on a undefined range,
        // so you get a "no button pressed at all"
        return debounce(NOBUTTON);
    }
}
