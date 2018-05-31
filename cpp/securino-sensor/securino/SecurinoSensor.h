#ifndef __SECURINO_SENSOR_H__
#define __SECURINO_SENSOR_H__

#include <Arduino.h>

class SecurinoSensor {
  
  public:
    
    SecurinoSensor(int _pin);
    ~SecurinoSensor();
    
    void check(uint8_t * dht);
    
  private:
    
    int pin;
  
};

#endif // __SECURINO_SENSOR_H__
