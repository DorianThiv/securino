#ifndef __LORA_SERVER_H__
#define __LORA_SERVER_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <memory>

#include <RH_RF95.h>

#include "MqttPublisher.h"

using namespace std;

class LoRaServer
{
	public:
		LoRaServer();
		~LoRaServer();

		void run();
        void stop();

    private:
        void setup();
        void loop();

        int running;
        shared_ptr<MqttPublisher> mqttPublisher;
};

#endif // __LORA_SERVER_H__
