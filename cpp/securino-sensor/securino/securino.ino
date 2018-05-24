
/** 
 * Securino object for integration
 */

#include "SecurinoSensor.h"
#include "SecurinoRFID.h"
#include "SecurinoLazer.h"

#define PIN_SENSOR 9
#define PIN_RFID 8
#define PIN_LAZER 7

SecurinoSensor * s_sensor;
SecurinoRFID * s_rfid;
SecurinoLazer * s_lazer;

int * sensorProcess() {
  int tempNhum [] = {26, 65};
  s_sensor->check();
  return tempNhum;
}

int * rfidProcess() {
  s_rfid->check();
  return "Hello";
}

boolean lazerProcess() {
  s_lazer->check();
  return true;
}

void setup() {
  
  s_sensor = new SecurinoSensor(PIN_SENSOR);
  s_rfid = new SecurinoRFID(PIN_RFID);
  s_lazer = new SecurinoLazer(PIN_LAZER);

}

void loop() {

}

