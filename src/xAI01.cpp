/*
	This is a library for the AI01 
	I2C MULTIPLEXER

	The board uses I2C for communication.
	
	The board communicates with the following I2C device:
	-	PCA9548
	
	Data Sheets:
	PCA9548 - https://www.ti.com/lit/ds/symlink/pca9548a.pdf
*/

#include <xAI01.h>
  
/*--Public Class Function--*/

/********************************************************
 	Constructor
*********************************************************/
xAI01::xAI01(void)
{
    PCA9548_I2C_ADDRESS = 0x70;
}

xAI01::xAI01(uint8_t addr)
{
    PCA9548_I2C_ADDRESS = addr; 
}

/********************************************************
 	Configure Sensor
*********************************************************/
bool xAI01::begin(void)
{
    if(xCore.ping(PCA9548_I2C_ADDRESS)) {
        return true;
    } else {
        return false;
    }
} 

/********************************************************
 	Enables a specific port number
*********************************************************/
bool xAI01::enableMuxPort(byte portNumber)
{
  if (portNumber > 7) portNumber = 7;

  //Read the current mux settings
  Wire.requestFrom(AI01_AD0, 1);
  if (!Wire.available()) return (false); //Error
  byte settings = Wire.read();

  //Set the wanted bit to enable the port
  settings |= (1 << portNumber);

  Wire.beginTransmission(PCA9548_I2C_ADDRESS);
  Wire.write(settings);
  Wire.endTransmission();

  return true;
}

/********************************************************
 	Disables a specific port number
*********************************************************/
bool xAI01::disableMuxPort(byte portNumber)
{
  if (portNumber > 7) portNumber = 7;

  //Read the current mux settings
  Wire.requestFrom(AI01_AD0, 1);
  if (!Wire.available()) return (false); //Error
  byte settings = Wire.read();

  //Clear the wanted bit to disable the port
  settings &= ~(1 << portNumber);

  Wire.beginTransmission(PCA9548_I2C_ADDRESS);
  Wire.write(settings);
  Wire.endTransmission();

  return true;
}