#ifndef __SECURINO_LAZER_H__
#define __SECURINO_LAZER_H__

#include <Arduino.h>

class SecurinoLazer {
  
  public:
    
    SecurinoLazer(int _pinLazer, int _pinDetector);
    ~SecurinoLazer();
    
  void check(uint8_t * laz);
    
  private:
    
    int pinLazer;
    int pinDetector;
  
};

#endif // __SECURINO_LAZER_H__
