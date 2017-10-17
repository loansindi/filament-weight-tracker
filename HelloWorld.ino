#include <HX711.h>

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 9
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 5
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>


HX711 scale (A3, A2);

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(0, INPUT_PULLUP);
  //digitalWrite(0, HIGH);
    attachInterrupt(digitalPinToInterrupt(0), tareScale, LOW);
    scale.set_scale();
    scale.tare();
    lcd.print("add weight, calibrating in 5s");
    delay(5000);
long    cal = scale.get_units(10);
    cal = cal/309;
    scale.set_scale(cal);
      lcd.setCursor(0,1);
  lcd.print("Grams");
  lcd.home();

}

void loop() {
  lcd.print(scale.get_units(5) - 309);
  lcd.print("            ");
  lcd.home();

  delay(1000);


}

void tareScale() {
  scale.tare();
}


