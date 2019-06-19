/*************************************************************
  This is an examples for the AI01
  I2C Multiplexer

  You can buy one on our store!
  -----> https://xinabox.cc/products/AI01

  This example uses the South Connector as incoming I2C
  multiplexed to the North Connector interfacing SW10.
  Temperature is displayed over serial terminal.

  Supported on the all ☒CHIPs

  The sensor communicates over the I2C Bus.

*************************************************************/
#include <xAI01.h>
#include <xSW10.h>

// Singleton Instance of the xChips
xAI01 AI01;
xSW10 SW10;

void setup() {
  // put your setup code here, to run once:
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the I2C Comunication
  Wire.begin();
  // Start the  AI01
  AI01.begin();
  // Enable North Connector
  AI01.enableMuxPort(MUX_N);

  // Start SW10 Temperature Sensor
  SW10.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  SW10.poll();
  Serial.println(SW10.getTempC());
  delay(2000);
}
