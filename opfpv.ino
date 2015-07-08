//XCAL 0x0006C647UL
//YCAL 0x019A4052UL
//ZCAL 0x000EF13FUL
#include "touchButton.h"
#include <UTFT.h>
#include <UTouch.h>
#include <avr/pgmspace.h>
#include <UTouch.h>

UTFT    myGLCD(ITDB32S, 38, 39, 40, 41);
UTouch  myTouch( 6, 5, 4, 3, 2);
extern uint8_t SmallFont[];
extern unsigned int opsmall[0x400];

touchButton power58 (myGLCD, 20, 120, 80, 80, 'p');
touchButton power58r (myGLCD, 220, 120, 80, 80, 'p');
touchButton power13 (myGLCD, 120, 120, 80, 80, 'p');
touchButton vswitch (myGLCD, 120, 20, 80, 80, 'v');

int tx, ty;



void setup() {
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  myGLCD.fillScr(51, 51, 51); //this is bg for OP logo
  myGLCD.drawBitmap(105, 70, 100, 100, opsmall);
  delay(3000);
  drawScreen();
  printText();
}

void loop() {
if (myTouch.dataAvailable())
    {
      myTouch.read();
      tx=myTouch.getX();
      ty=myTouch.getY();
      checkButtons();
      drawScreen();
    }


}

void printText() {
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(51, 51, 51);
  myGLCD.print("5.8 GHz Rx", 21, 205);
  myGLCD.print("1.2 GHz Rx", 121, 205);
  myGLCD.print("5.8 Repeat", 221, 205);
  myGLCD.print("Monitor Input", 110, 3);
}

void drawScreen() {
  myGLCD.fillScr(51, 51, 51);
  power58r.Draw();
  power58.Draw();
  power13.Draw();
  vswitch.Draw();
  printText();
}

void checkButtons(){
 if(power58.isTouched(tx, ty)){
  power58.Press();
 } 
 
 if(power58r.isTouched(tx, ty)){
  power58r.Press();
 } 
 
 if(power13.isTouched(tx, ty)){
  power13.Press();
 } 
 
 if(vswitch.isTouched(tx, ty)){
  vswitch.Press();
 } 
}
