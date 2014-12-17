/*
  Digital Pot Control

  This example controls an Analog Devices AD5206 digital potentiometer.
  The AD5206 has 6 potentiometer channels. Each channel's pins are labeled
  A - connect this to voltage
  W - this is the pot's wiper, which changes when you set it
  B - connect this to ground.

 The AD5206 is SPI-compatible,and to command it, you send two bytes,
 one with the channel number (0 - 5) and one with the resistance value for the
 channel (0 - 255).

 The circuit:
  * All A pins  of AD5206 connected to +5V
  * All B pins of AD5206 connected to ground
  * An LED and a 220-ohm resisor in series connected from each W pin to ground
  * CS - to digital pin 10  (SS pin)
  * SDI - to digital pin 11 (MOSI pin)
  * CLK - to digital pin 13 (SCK pin)

 created 10 Aug 2010
 by Tom Igoe

 Thanks to Heather Dewey-Hagborg for the original tutorial, 2005

*/


// inslude the SPI library:
#include <SPI.h>
#include<string.h>

#define MIN_DUTY 260
#define MAX_DUTY 1200


#define CMD_SET_ON_OFF 0x01
#define CMD_SET_POLARITY 0x02
#define CMD_SET_FREQ 0x03
#define CMD_SET_DUTY 0x04

// set pin 10 as the slave select for the digital pot:
#define slaveSelectPin  10

char UartBuffer[128];
unsigned short duty;



void DeviceSynchronize(void)
{
   SPI.transfer(0);
   SPI.transfer(0);
   SPI.transfer(0);
   SPI.transfer(0);
   SPI.transfer(0);
   SPI.transfer(0);
   SPI.transfer(0);
   SPI.transfer(0);
}


void SendCmd(unsigned char cmd,unsigned char index,unsigned short value)
{
   unsigned char CheckSum;
   unsigned char valueL;
   unsigned char valueH;
 

    valueL = value & 0xff;
    valueH = ((value>>8) & 0xff);
    CheckSum = 0x87; 
    SPI.transfer(0x87);
    SPI.transfer(cmd);
    CheckSum += cmd;
    SPI.transfer(index);//index
    CheckSum += index;
    SPI.transfer(valueL);
    CheckSum += valueL;
    SPI.transfer(valueH);
    CheckSum += valueH;
    SPI.transfer(CheckSum);//CheckSum
    //sprintf(UartBuffer,"Send data:0x%02x--0x%02x--0x%02x--0x%02x--0x%02x--0x%02x\n",0x87,cmd,index,valueL,valueH,CheckSum);
    //Serial.print(UartBuffer); 
}


void SetPwmOnOff(unsigned char index,boolean on)
{
   SendCmd(CMD_SET_ON_OFF,index,on); 
}

void SetPwmDuty(unsigned char index,unsigned short duty)
{
   SendCmd(CMD_SET_DUTY,index,duty); 
}

void SetPwmFrequency(unsigned char index,unsigned short frequency)
{
   SendCmd(CMD_SET_FREQ,index,frequency); 
}




void setup() 
{
  char i;
  // set the slaveSelectPin as an output:
  pinMode (slaveSelectPin, OUTPUT);
  // initialize SPI:
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV2);  
  Serial.begin(9600);
  memset(UartBuffer,0x00,sizeof(UartBuffer));
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  duty=MIN_DUTY; 
  DeviceSynchronize(); 
  for(i=0;i<27;i++)SetPwmDuty(i,duty); 
}



void loop() {
  // put your main code here, to run repeatedly: 
  char i;
  char tmpChar;

 if(Serial.available())
  {
    tmpChar = Serial.read();
    if (tmpChar == '8')
    {
      if(duty <MAX_DUTY)
      {
        duty += 10;
        for(i=0;i<27;i++)SetPwmDuty(i,duty); 
      }
    }
    else if (tmpChar == '2')
    {
       if(duty >MIN_DUTY)
        {
          duty -= 10;
         for(i=0;i<27;i++)SetPwmDuty(i,duty); 
        }
      } 
     else if (tmpChar == 'f')
     {
        for(i=0;i<27;i++) SetPwmOnOff(i,0);
     }   
     else if (tmpChar == 'n')
     {
      for(i=0;i<27;i++) SetPwmOnOff(i,1);
     }  
     sprintf(UartBuffer,"set complete,duty = %d\r",duty);
     Serial.print(UartBuffer); 
  }  
}
