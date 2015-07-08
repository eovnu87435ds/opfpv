#include "Arduino.h"
#include "touchButton.h"
#include <UTFT.h>
#include <UTouch.h>

touchButton::touchButton(UTFT &glcddev, int x, int y, int xs, int ys, char myuse)
{
  x1 = x;
  y1 = y;
  xsize = xs;
  ysize = ys;
  use = myuse;
  glcd = &glcddev;
  toggle = false;
}

boolean touchButton::isTouched(int tx, int ty){
  if(tx>= x1 && tx<=(x1+xsize) && ty>= y1 && ty<=(y1+ysize)){
    return(true);
  }
  else {
    return(false);
  }
}

void touchButton::Press(){
  toggle = !toggle;
}

void touchButton::Draw() {
  switch (use) {
    case 'p': /////////////////////////////////////////////////////////////////////////////////////////
      /////////////// POWER TOGGLE

      if (toggle) {
        glcd->setColor(VGA_GREEN);
      }
      else {
        glcd->setColor(VGA_RED);
      }

      glcd->fillRoundRect(x1, y1, x1 + xsize, y1 + ysize);
      glcd->setColor(VGA_BLACK);
      glcd->drawCircle(x1 + (xsize / 2), y1 + (ysize * 0.6), (xsize * 0.2));
      glcd->drawLine(x1 + (xsize / 2), y1 + (ysize * 0.1), x1 + (xsize / 2), y1 + (ysize * 0.6));
      break;

    case 'v': /////////////////////////////////////////////////////////////////////////////////////////
      /////////////// VIDEO TOGGLE
      glcd->setColor(VGA_BLUE);
      glcd->fillRoundRect(x1, y1, x1 + xsize, y1 + ysize);
      glcd->setColor(VGA_BLACK);
      glcd->drawLine(x1 + (xsize / 2), y1 + (ysize * 0.2), x1 + (xsize * 0.3), y1 + (ysize * 0.4)); // ^ LEFT
      glcd->drawLine(x1 + (xsize / 2), y1 + (ysize * 0.2), x1 + (xsize * 0.7), y1 + (ysize * 0.4)); // ^ RIGHT
      if (!toggle) {
        glcd->drawLine(x1 + (xsize / 2), y1 + (ysize * 0.2), x1 + (xsize / 2), y1 + (ysize * 0.8)); // |
        glcd->setColor(VGA_WHITE);
        glcd->setBackColor(VGA_BLUE);
        glcd->print("1.2", (x1+xsize*0.7), y1+(ysize*0.7));
      }
      else {
        glcd->drawLine(x1 + (xsize / 2), y1 + (ysize * 0.2), x1 + (xsize * 0.5), y1 + (ysize * 0.6)); // |
        glcd->drawLine(x1 + (xsize / 2), y1 + (ysize *0.6), x1 + (xsize * 0.2), y1 + (ysize * 0.8)); // /
        glcd->setColor(VGA_WHITE);
        glcd->setBackColor(VGA_BLUE);
        glcd->print("5.8", (x1+xsize*0.7), y1+(ysize*0.7));
      }


    default:
      x1 = x1 + 1;
      break;
  }


}




