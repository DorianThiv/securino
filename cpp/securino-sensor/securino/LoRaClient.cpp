
#include "LoRaCLient.h"

RH_RF95 rf95;

LoRaClient::LoRaClient()
{
    setup();
}

void LoRaClient::setup() 
{
    //  pinMode(4, OUTPUT);
    //  digitalWrite(4, HIGH);

    Serial.begin(9600);
    while (!Serial) ;
    if (!rf95.init())
        Serial.println("init failed");

    rf95.setTxPower(20);
    rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128);
    rf95.setFrequency(868.0);
}

void LoRaClient::send(uint8_t data[])
{
    Serial.println("Sending ...");
    rf95.send(data, sizeof(data));
    rf95.waitPacketSent();
    Serial.println("Packet sended");
}