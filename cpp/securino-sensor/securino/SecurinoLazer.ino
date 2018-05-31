#include "SecurinoLazer.h"

SecurinoLazer::SecurinoLazer(int _pinLazer, int _pinDetector) {
  pinLazer = _pinLazer;
  pinDetector = _pinDetector;
  pinMode(pinLazer, OUTPUT);
  pinMode(pinDetector, INPUT);

}
/*
 * Arduino :    A    Octet 0 65
 * TYPE :       L    Octet 1 76
 * Laser:               Octet 2
 */
void SecurinoLazer::check(uint8_t * laz) {
  digitalWrite(pinLazer, HIGH);
  boolean val = digitalRead(pinDetector);
  
  laz[0] = 65;
  laz[1] = 76;
  laz[2] = val;
 

  Serial.print(laz[0]);
  Serial.print(laz[1]);
  Serial.println(laz[2]);

}
