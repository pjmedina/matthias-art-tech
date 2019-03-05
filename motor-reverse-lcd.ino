

int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int potPin = 0;
int speed;
bool reverse;
double count = 0.5;

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;


void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT); 
  pinMode(enablePin, OUTPUT);

  lcd.begin(16, 2);
    
  lcd.setRGB(colorR, colorG, colorB);
  
  
  // Print a message to the LCD.
  lcd.setCursor(2, 0);
  lcd.print("I Am That Is");
}

void loop()
{
    reverse = !reverse;
    speed = analogRead(potPin) / 4;
    // set the cursor to column 0, line 1
    lcd.setCursor(0, 1);
    // print the number of seconds
    lcd.print(count);
    lcd.setCursor(12, 1);
    lcd.print("days");
    setMotor(speed, reverse);
    delay(24000); 

}

void setMotor(int speed, boolean rev)
{
  count = count + 0.5;
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !rev);
  digitalWrite(in2Pin, rev);
}
