
#include <anabuttons.h>
#include <LiquidCrystal.h>

#define KEYS_PIN  2

// lcd pins assuming a 1602 (16x2) at 4 bits
#define LCD_RS      8    // 14
#define LCD_E       7    // 13
#define LCD_D4      6    // 12
#define LCD_D5      5    // 11
#define LCD_D6      10   // 16
#define LCD_D7      9    // 15

// lcd library declaration
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// analog buttons library declaration (constructor)
AnaButtons ab = AnaButtons(KEYS_PIN);

// define the var that will hold the value
byte val           = 0;


void printLcd(byte val) {
    lcd.setCursor(0,1);
    lcd.print("Button Press: ");
    lcd.print(val);
}


void setup() {
    // LCD init
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("AnaButtons test ");
}


void loop() {
    val = ab.getStatus();

    if (val != 0) {
        // switch on the result
        switch (val) {
            // press
            case ABUTTON1_PRESS:
                printLcd(val);
                break;
            case ABUTTON2_PRESS:
                printLcd(val);
                break;
            case ABUTTON3_PRESS:
                printLcd(val);
                break;
            case ABUTTON4_PRESS:
                printLcd(val);
                break;
            case ABUTTON5_PRESS:
                printLcd(val);
                break;
            case ABUTTON6_PRESS:
                printLcd(val);
                break;
        }
    }
}
