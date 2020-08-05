#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 tm1637(CLK, DIO);
int8_t TimeDisp[] = {0x08, 0x08, 0x08, 0x08};
int8_t Year = 20;
int8_t Moon = 8;
int8_t Day = 2;
int8_t Hour = 20;
int8_t Min = 47;
int8_t Sec = 0;
String inputString = "";
void setup()
{
  Serial.begin(9600);
  Serial.println("Serial interface between PC and chipKIT");
  tm1637.init();
  tm1637.set(BRIGHT_DARKEST); //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7
  tm1637.point(POINT_ON);
  tm1637.display(TimeDisp);
  delay(2500);
  tm1637.point(POINT_OFF);
  tm1637.clearDisplay();
  delay(2500);
}

void loop()
{
  
  while (Serial.available())       //判断是否接收到数据
  {
    inputString = inputString + char(Serial.read());
    delay(2);
  }
   

  if (inputString!="") {
    int brry = inputString.toInt();
    Hour = brry / 100;
    Min  = brry % 100;
    Sec  =  0;
    inputString = "";
  }
  
  Sec++;
  if (Sec == 60) {
    Sec = 0;
    Min++;
    Serial.println(TimeDisp);//看看能不能打印出来
    if (Min == 60) {
      Min = 0;
      Hour++;
      if (Hour == 24) {
        Hour = 0;
      }
    }
  }

  TimeDisp[0] = Hour / 10;
  TimeDisp[1] = Hour % 10;
  TimeDisp[2] = Min / 10;
  TimeDisp[3] = Min % 10;
  tm1637.point(POINT_ON);
  tm1637.display(TimeDisp);
  delay(499);
  tm1637.point(POINT_OFF);
  tm1637.display(TimeDisp);
  delay(499);
}
