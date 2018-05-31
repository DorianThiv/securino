#include "SecurinoDecoder.h"

void SecurinoDecoder::decode(char * destbuf, uint8_t * frame, uint8_t size)
{
    if (frame[1] == TYPE_SENSOR_DHT)
    {
        if (frame[2] == TYPE_SENSOR_DHT_TEMP)
            decodeDhtTemp(destbuf, frame, size);
        else if (frame[2] == TYPE_SENSOR_DHT_HUMIDITY)
            decodeDhtHumi(destbuf, frame, size);
    }
    else if (frame[1] == TYPE_SENSOR_LAZER)
        decodeLazer(destbuf, frame, size);
}

void SecurinoDecoder::decodeDhtTemp(char * destbuf, uint8_t * frame, uint8_t size)
{
    printf("=> Decode DHT Temperature ...\n");

    int temperature = frame[B_SENSOR_DHT_TEMP];

    const char * f_temp = "{ \"device\": \"Arduino Uno\", \"sensor\": \"temperature\", \"value\": %d, \"unit\": \"°C\" }";
    sprintf(destbuf, f_temp, temperature);

    printf("Temperature : %d °C\n", temperature);
}

void SecurinoDecoder::decodeDhtHumi(char * destbuf, uint8_t * frame, uint8_t size)
{
    printf("=> Decode DHT Humidity ...\n");

    int humidity = frame[B_SENSOR_DHT_HUMIDITY];

    const char * f_humi = "{ \"device\": \"Arduino Uno\", \"sensor\": \"humidity\", \"value\": %d, \"unit\": \"%\" }";
    sprintf(destbuf, f_humi, humidity);

    printf("Humidity : %d \n", humidity);
}


void SecurinoDecoder::decodeLazer(char * destbuf, uint8_t * frame, uint8_t size)
{
    printf("=> Decode Lazer\n");

    int status = frame[B_SENSOR_LAZER_VALUE];

    const char * f_res = "{ \"device\": \"Arduino Uno\", \"sensor\": \"Lazer\", \"value\": %d, \"unit\": \"\" }";
    sprintf(destbuf, f_res, status);

    printf("Laser status : %d\n", status);
}

