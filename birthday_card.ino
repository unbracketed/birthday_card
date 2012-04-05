
/* Birthday Card

ShiftPWM RGB LED ring with tone speaker
Each LED is assigned to a tone
Rainbow effect at end of song
*/

#include <SPI.h>
#include "hsv2rgb.h"
#include "pitches.h"

//Data pin is MOSI (atmega168/328: pin 11. Mega: 51) 
//Clock pin is SCK (atmega168/328: pin 13. Mega: 52)
const int ShiftPWM_latchPin=8;
const bool ShiftPWM_invertOutputs = 0; // if invertOutputs is 1, outputs will be active low. Usefull for common anode RGB led's.

#include <ShiftPWM.h>   // include ShiftPWM.h after setting the pins!


//Music settings
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };


//ShiftPWM settings
unsigned char maxBrightness = 200;
unsigned char pwmFrequency = 75;
int numRegisters = 3;

void setup()   {                
  pinMode(ShiftPWM_latchPin, OUTPUT);  
  SPI.setBitOrder(LSBFIRST);
  // SPI_CLOCK_DIV2 is only a tiny bit faster in sending out the last byte. 
  // SPI transfer and calculations overlap for the other bytes.
  SPI.setClockDivider(SPI_CLOCK_DIV4); 
  SPI.begin(); 

  Serial.begin(9600);


  ShiftPWM.SetAmountOfRegisters(numRegisters);
  ShiftPWM.Start(pwmFrequency,maxBrightness);  
  
  ShiftPWM.SetAll(0);
}

void loop() {
}
