
#include "TM1637.h"

#define CLK 3
#define DIO 2

TM1637 tm1637(CLK, DIO);
int8_t TimeDisp[] = {0x00, 0x00, 0x00, 0x00};

void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_DARKEST); //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop()
{
  if (ClockPoint)
  {
    tm1637.point(POINT_ON);
  }
  else
  {
    tm1637.point(POINT_OFF);
  }

  for (j = 0; j < 10; j++)
  {
    for (i = 0; i < 10, i++)
    {
      for (a = 0; a < 10, a++)
      {
        for (b = 0; b < 10, b++)
        {
          TimeDisp[] = {j, i, a, b};
          tm1637.display(TimeDisp);
          delay(500);
        }
      }
    }
  }
}
