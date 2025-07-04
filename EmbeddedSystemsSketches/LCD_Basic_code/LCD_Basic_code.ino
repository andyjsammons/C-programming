#include <LiquidCrystal.h>

// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup() {
lcd.begin(16, 2); // set up the LCD's number of columns and rows 
lcd.print("hello, world!");  // Print a message to the LCD
}

void loop() {

// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):

lcd. setCursor (0, 1);
lcd.print(millis() / 1000); // print the number of seconds since reset delay (100);

}