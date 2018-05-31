
/**********************************************************
*
*                     MQTT Publisher
*
*                    THIVOLLE Dorian
*                dorian_thivolle@orange.fr
*                         CASIR
*
***********************************************************/

#include <mosquittopp.h>

#ifndef __MQTT_PUBLISHER_H__
#define __MQTT_PUBLISHER_H__

class MqttPublisher : public mosqpp::mosquittopp
{
	public:
		MqttPublisher(const char *id, const char *host, int port);
		~MqttPublisher();

		void on_publish(char * message);
		void on_connect(int rc);
		void on_message(const struct mosquitto_message *message);
		void on_subscribe(int mid, int qos_count, const int *granted_qos);
};

#endif // __MQTT_PUBLISHER_H__
