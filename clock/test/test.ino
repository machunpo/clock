#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 tm1637(CLK, DIO);
int8_t TimeDisp[] = {0x08, 0x08, 0x08, 0x08};
int8_t Year = 20;
int8_t Moon = 8;
int8_t Day = 2;
int8_t Hour = 20;
int8_t Min = 30;
int8_t Sec = 0;

void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_DARKEST); //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  tm1637.point(POINT_ON);
  tm1637.display(TimeDisp);
  delay(2500);
  tm1637.point(POINT_OFF);
  tm1637.clearDisplay();
  delay(2500);
}

void loop()
{

  for (; Hour < 24; Hour++)
  {
    for (; Min < 60; Min++)
    {
      for (; Sec < 60; Sec++)
      {
        TimeDisp[0] = Hour / 10;
        TimeDisp[1] = Hour % 10;
        TimeDisp[2] = Min / 10;
        TimeDisp[3] = Min % 10;
        tm1637.point(POINT_ON);
        tm1637.display(TimeDisp);
        delay(500);
        tm1637.point(POINT_OFF);
        tm1637.display(TimeDisp);
        delay(500);
      }
      Sec = 0;
    }
    Min = 0;
  }
  Hour = 0;
}
// Whether to light the clock point ":".是否点亮时钟点“：
// To take effect the next time it displays.下次显示时生效
/*

if(count == 20)
         {
            count = 0;
            sec++;
            if(sec == 60)
            {
                sec = 0;
                min++;
                if(min == 60)
                {
                    min = 0;
                    hour++;
                    if(hour == 24)
                    {
                        hour = 0;
                    }
                }
            }

*/