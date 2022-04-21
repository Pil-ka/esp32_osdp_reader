#include <osdp_reader.h>

#define TX_MODE_PIN 5 // rs485 module DE, RE
//#define R_LED_PIN 33
//#define G_LED_PIN 25
//#define B_LED_PIN 26
//#define BUZ_PIN 14
#define RX2_PIN 16 // rs485 module RO 
#define TX2_PIN 17 // rs485 module DI

osdp_reader reader(Serial, Serial2, TX_MODE_PIN);

void setup() {

  Serial.begin(115200); // for debugging purposes
  Serial2.begin(9600, SERIAL_8N1, RX2_PIN, TX2_PIN); // Serial2 is used for communicating with OSDP CP via rs485 
  reader.init();
}

void loop() {
  reader.loop();
}
