
#include <memory>

#include "MqttPublisher.h"


int main(int argc, char *argv[])
{
	std::shared_ptr<MqttPublisher> mqttPublisher;
	int rc;

	mosqpp::lib_init();

	mqttPublisher = std::make_shared<MqttPublisher>("frequency_publisher", "localhost", 1883);
	mqttPublisher->on_publish("Hello");

	mosqpp::lib_cleanup();

	return 0;
}

