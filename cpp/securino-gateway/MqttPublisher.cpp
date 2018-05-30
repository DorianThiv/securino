#include <cstdio>
#include <cstring>

#include "MqttPublisher.h"
#include <mosquittopp.h>

MqttPublisher::MqttPublisher(const char *id, const char *host, int port) : mosquittopp(id)
{
	int keepalive = 60;
	connect(host, port, keepalive);
    printf("[$] MQTT initialized\n");
};

MqttPublisher::~MqttPublisher() { }

void MqttPublisher::on_publish(char * message)
{
	publish(NULL, "arduino/temp", strlen(message), message);
	printf("[$] Publish : %s\n", message);
}

void MqttPublisher::on_connect(int rc)
{
	if(rc == 0){
		printf("Connected with code %d.\n", rc);
	}
}

void MqttPublisher::on_message(const struct mosquitto_message *message)
{
	printf("On Message : %p", message->payload);
}

void MqttPublisher::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");
}

