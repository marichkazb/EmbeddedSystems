#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char mapping[4][4] = {
  			  {'1', '2', '3', 'A'},
              {'4', '5', '6', 'B'},
              {'7', '8', '9', 'C'},
              {'*', '0', '#', 'D'}
             };

byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5, 4};


Keypad customKeypad = Keypad(makeKeymap(mapping), rowPins, colPins, ROWS, COLS);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char cKey = customKeypad.getKey();
  
  if (cKey)
  {
    Serial.println(cKey);
  }
}