#include "SecurinoDecoder.h"

void SecurinoDecoder::decode(char * destbuf, uint8_t * frame, uint8_t size)
{
    if (frame[1] == TYPE_SENSOR_DHT)
        decodeDHT(destbuf, frame, size);
    else if (frame[1] == TYPE_SENSOR_LAZER)
        decodeLazer(destbuf, frame, size);
}

void SecurinoDecoder::decodeDHT(char * destbuf, uint8_t * frame, uint8_t size)
{
    printf("Decode DHT\n");
    int i = 0;
    while (i < size)
    {
        i++;
    }
}

void SecurinoDecoder::decodeLazer(char * destbuf, uint8_t * frame, uint8_t size)
{
    printf("Decode Lazer\n");
    int i = 0;
    while (i < size)
    {
        i++;
    }
}

