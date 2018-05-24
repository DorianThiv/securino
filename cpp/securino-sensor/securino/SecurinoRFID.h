#ifndef __SECURINO_RFID_H__
#define __SECURINO_RFID_H__

class SecurinoRFID {
  
  public:
    
    SecurinoRFID(int _pin);
    ~SecurinoRFID();
    
    void check();
    
  private:
    
    int pin;
  
};

#endif // __SECURINO_RFID_H__
