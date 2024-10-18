#include <Arduino.h>

///////////////////////////////////////////////////////////////////////////
// Project : CycleClock
// Author : Loris Bousselat
// Date : 2024-October-18
// Equipment used : eps32    7-segment Display with 74HC595
// Description :
//   Make a segment run arround the display
///////////////////////////////////////////////////////////////////////////

const int STcp = 27; // ST_CP
const int SHcp = 26; // SH_CP
const int DS = 25;   // DS

int datArray[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000};
int datSize = sizeof(datArray) / sizeof(datArray[0]);

void setup()
{
  // set pins to output
  pinMode(STcp, OUTPUT);
  pinMode(SHcp, OUTPUT);
  pinMode(DS, OUTPUT);
}

void loop()
{
  for (int i = 0; i < datSize; i++)
  {
    digitalWrite(STcp, LOW); // ground ST_CP and hold low for as long as you are transmitting
    shiftOut(DS, SHcp, MSBFIRST, datArray[i]);
    digitalWrite(STcp, HIGH); // pull the ST_CPST_CP to save the data
    delay(100);
  }
}
