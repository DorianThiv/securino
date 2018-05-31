#ifndef __LORA_CLIENT_H__
#define __LORA_CLIENT_H__

#include <Arduino.h>
#include <SPI.h>
#include <RH_RF95.h>

class LoRaClient {
  
    public:
        
        LoRaClient();
        ~LoRaClient();
        
        void send(uint8_t * data, uint8_t ssize);

    private:

        void setup();
  
};

#endif // __LORA_CLIENT_H__
