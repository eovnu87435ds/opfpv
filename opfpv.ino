#include <UTFT.h>
#include <UTouch.h>
#include <avr/pgmspace.h>
UTFT    myGLCD(ITDB32S, 38, 39, 40, 41);
UTouch  myTouch( 6, 5, 4, 3, 2);
extern uint8_t SmallFont[];
extern unsigned int opsmall[0x400];

void setup() {
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  myGLCD.fillScr(51, 51, 51); //this is bg for OP logo
  myGLCD.drawBitmap(105, 70, 100, 100, opsmall);

}

void loop() {
  // put your main code here, to run repeatedly:

}
