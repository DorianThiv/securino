#ifndef __SECURINO_RFID_H__
#define __SECURINO_RFID_H__
#include <Arduino.h>


class SecurinoRFID {
  
  public:
    
    SecurinoRFID(int _pinRfid1, int _pinRfid2);
    ~SecurinoRFID();
    
    void check();
    
  private:
    
    int pinRfid1;
    int pinRfid2;
  
};

#endif // __SECURINO_RFID_H__
