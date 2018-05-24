#ifndef __SECURINO_LAZER_H__
#define __SECURINO_LAZER_H__

class SecurinoLazer {
  
  public:
    
    SecurinoLazer(int _pin);
    ~SecurinoLazer();
    
    void check();
    
  private:
    
    int pin;
  
};

#endif // __SECURINO_LAZER_H__
