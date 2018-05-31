
#ifndef __SECURINO_DECODER_H__
#define __SECURINO_DECODER_H__

#include <stdio.h>
#include <stdint.h>

#define B_DEVICE 0;
#define B_SENSOR 1;

#define TYPE_SENSOR_DHT 66;
#define TYPE_SENSOR_LAZER 76

class SecurinoDecoder {

    public:

        SecurinoDecoder() { }
        ~SecurinoDecoder() { }

        static void decode(uint8_t * destbuf, uint8_t * frame, uint8_t size);

    private:

        static void decodeDHT(uint8_t * destbuf, uint8_t * frame, uint8_t size);
        static void decodeLazer(uint8_t * destbuf, uint8_t * frame, uint8_t size);
};

#endif // __SECURINO_DECODER_H__
