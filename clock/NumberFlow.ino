#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 tm1637(CLK, DIO);


void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_DARKEST); //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop()
{
  int8_t TimeDisp[] = {0x08, 0x08, 0x08, 0x08};
  tm1637.display(TimeDisp);
  delay(2500);

  for (int8_t j = 0; j < 10; j++)
  {
    for (int8_t i = 0; i < 10; i++)
    {
      for (int8_t a = 0; a < 10 ;a++)
      {
        for (int8_t b = 0; b < 10; b++)
        {
          TimeDisp[0] = j;
          TimeDisp[1] = i;
          TimeDisp[2] = a;
          TimeDisp[3] = b;
          tm1637.display(TimeDisp);
          delay(200);
        }
      }
    }
  }
}
