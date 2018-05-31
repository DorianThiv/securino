/** 
 * Securino object for integration
 */

#include "LoRaClient.h"
#include "SecurinoSensor.h"
#include "SecurinoRFID.h"
#include "SecurinoLazer.h"

#define PIN_SENSOR 5
#define PIN_RFID1 10
#define PIN_RFID2 9
#define PIN_LAZER 6
#define PIN_DETECTOR 7

#define TAB_SIZE_SENSOR 4
#define TAB_SIZE_LAZER 3

LoRaClient * s_lora;
SecurinoSensor * s_sensor;
SecurinoRFID * s_rfid;
SecurinoLazer * s_lazer;

uint8_t tabdht[TAB_SIZE_SENSOR];
uint8_t tablazer[TAB_SIZE_LAZER];
uint8_t tabrfid[3];

void processDht()
{
	s_sensor->check(tabdht);
	uint8_t * temp = tabdht[2];
	uint8_t * humi = tabdht[3];
	uint8_t tabdt[TAB_SIZE_SENSOR] = tabdht;
	uint8_t tabdh[TAB_SIZE_SENSOR] = tabdht;
	tabdt[2] = 84;
	tabdt[3] = temp;
	tabdh[2] = 72;
	tabdh[3] = humi;
	s_lora->send(tabdt, TAB_SIZE_SENSOR);
	s_lora->send(tabdh, TAB_SIZE_SENSOR);
}

void processLazer()
{
	s_lazer->check(tablazer);
	if (tablazer[2] == 1) {
		s_lora->send(tablazer, TAB_SIZE_LAZER);
	}
}


void setup() {
  Serial.begin(9600);
  s_lora = new LoRaClient();
  s_sensor = new SecurinoSensor(PIN_SENSOR);
  s_rfid = new SecurinoRFID(PIN_RFID1, PIN_RFID2);
  s_lazer = new SecurinoLazer(PIN_LAZER, PIN_DETECTOR);

}

void loop() {

	processDht();
	processLazer();
  
  	delay(5000);
}

