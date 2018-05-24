#ifndef __SECURINO_SENSOR_H__
#define __SECURINO_SENSOR_H__

class SecurinoSensor {
  
  public:
    
    SecurinoSensor(int _pin);
    ~SecurinoSensor();
    
    void check();
    
  private:
    
    int pin;
  
};

#endif // __SECURINO_SENSOR_H__
