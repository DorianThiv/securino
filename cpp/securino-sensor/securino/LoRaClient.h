#ifndef __LORA_CLIENT_H__
#define __LORA_CLIENT_H__

#include <SPI.h>
#include <RH_RF95.h>

class LoRaClient {
  
    public:
        
        LoRaClient();
        ~LoRaClient();
        
        void send(uint8_t data[]);

    private:

        void setup();
  
};

#endif // __LORA_CLIENT_H__