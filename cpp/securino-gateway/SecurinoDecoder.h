/**********************************************************
*
*                    Securino Decoder
*
*                    THIVOLLE Dorian
*                dorian_thivolle@orange.fr
*                         CASIR
*
***********************************************************/

/**********************************************************
*                    Securino Decoder
* ---------------------------------------------------------
* Decode frame from arduino
* Specs:
*   - 0x41 0x42 0x1a 0x17 : DHT frame
*   - 0x41 0x4c 0x00      : Lazer frame
**********************************************************/

#ifndef __SECURINO_DECODER_H__
#define __SECURINO_DECODER_H__

#include <stdio.h>
#include <stdint.h>

#include <iostream>

#define B_DEVICE 0
#define B_SENSOR 1

#define TYPE_SENSOR_DHT 66
#define TYPE_SENSOR_DHT_TEMP 84
#define TYPE_SENSOR_DHT_HUMIDITY 72
#define TYPE_SENSOR_LAZER 76

#define B_SENSOR_DHT_TEMP 2
#define B_SENSOR_DHT_HUMIDITY 3
#define B_SENSOR_LAZER_VALUE 2

class SecurinoDecoder {

    public:

        SecurinoDecoder() { }
        ~SecurinoDecoder() { }

        static void decode(char * destbuf, uint8_t * frame, uint8_t size);

    private:

        static void decodeDhtTemp(char * destbuf, uint8_t * frame, uint8_t size);
        static void decodeDhtHumi(char * destbuf, uint8_t * frame, uint8_t size);
        static void decodeLazer(char * destbuf, uint8_t * frame, uint8_t size);

};

#endif // __SECURINO_DECODER_H__
