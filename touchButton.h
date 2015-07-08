#ifndef touchButton_h
#define touchButton_h

#include "Arduino.h"
#include <UTFT.h>
#include <UTouch.h>
class touchButton
{
  public:
    touchButton(UTFT &glcddev, int x, int y, int xs, int ys, char use);
    void Draw();
    int x1;
    int y1;
    int xsize;
    int ysize;
    char use;
    boolean toggle = false;
    boolean isTouched(int tx, int ty);
    void Press();
    
  private:
    UTFT *glcd;
    
};

#endif
