#include "SecurinoRFID.h"

#include <SPI.h>
#include <RFID.h>

RFID RFID(10,9);
int UID[5];

SecurinoRFID::SecurinoRFID(int _pinRfid1, int _pinRfid2) {
  pinRfid1 = _pinRfid1;
  pinRfid2 = _pinRfid2;
  SPI.begin();
  RFID.init();  

}

void SecurinoRFID::check() {
if (RFID.isCard()) { 
	if (RFID.readCardSerial()) {        
		Serial.print("L'UID est: ");
		for(int i=0;i<=4;i++)
		{
		  UID[i]=RFID.serNum[i];
		  Serial.print(UID[i],DEC);
		  Serial.print(".");
		}
		Serial.println("");
	  }          
	  RFID.halt();
    }
}
