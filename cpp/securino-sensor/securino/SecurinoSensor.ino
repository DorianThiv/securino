#include "SecurinoSensor.h"
#include <dht.h>

dht DHT;

SecurinoSensor::SecurinoSensor(int _pin) {
  pin = _pin;
}

/*
 * Arduino :    A    Octet 0 65
 * DHT :        D    Octet 1 66
 * Temperature:         Octet 2
 * Humidity:            Octet 3
 */
void SecurinoSensor::check(uint8_t * dht) {
    int chk = DHT.read11(pin);
    dht[0] = 65;
    dht[1] = 66;
    dht[2] = DHT.temperature;
    dht[3] = DHT.humidity;
    
    //Serial.print("Temperature = ");
    //Serial.println(DHT.temperature);
    //Serial.print("Humidity = ");
    //Serial.println(DHT.humidity);
    Serial.print(dht[0]);
    Serial.print(dht[1]);
    Serial.print(dht[2]);
    Serial.println(dht[3]);

}
