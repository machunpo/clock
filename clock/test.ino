#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 tm1637(CLK, DIO);
int8_t TimeDisp[] = {0x00, 0x00, 0x00, 0x00};
int8_t Year = 20;
int8_t Moon =  8;
int8_t Day  =  2;
int8_t Hour = 20;
int8_t Min  =  0;
int8_t Sec  =  0;


void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_DARKEST); //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  tm1637.point(POINT_ON);
  tm1637.display(TimeDisp);
  delay(2500);
  tm1637.clearDisplay();
  delay(2500);
  //whether point light down?
}

void loop()
{
  //int8_t TimeDisp[] = {0x08, 0x08, 0x08, 0x08};
  for (int8_t j = 0; j < 10; j++)
  {
    for (int8_t i = 0; i < 10; i++)
    {
      for (int8_t a = 0; a < 10 ;a++)
      { 
      // Whether to light the clock point ":".是否点亮时钟点“：
      // To take effect the next time it displays.下次显示时生效
        for (int8_t b = 0; b < 10; b++)
        {
          TimeDisp[0] = j;
          TimeDisp[1] = i;
          TimeDisp[2] = a;
          TimeDisp[3] = b;
          tm1637.point(POINT_ON);
          tm1637.display(TimeDisp);
          delay(300);
          tm1637.point(POINT_OFF);
          tm1637.display(TimeDisp);
          delay(300);
        }
      }
    }
  }
}
//next time to define the Sec
