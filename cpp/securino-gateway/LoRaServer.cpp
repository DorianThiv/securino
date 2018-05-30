/*
 * Snootlab 
 *-----------------------------------------------------------------------------------------
 * Example of a communication between two Chistera-Pi or between a Chistera-Pi and a sensor
 * with a RFM95 like Snootlab's TeensyWiNo.
 * This is the receiver code, the Chistera-Pi receives a message with an address and a 
 * counter and it prints the informations on the prompt.
 *
 */

#include "LoRaServer.h"

RH_RF95 rf95;

int run = 1;

LoRaServer::LoRaServer()
{
    run = 1;
    signal(SIGINT, sigint_handler);
    setup();
}

void LoRaServer::setup()
{ 
    wiringPiSetupGpio();

    if (!rf95.init()) 
    {
        fprintf(stderr, "Init failed\n");
        exit(1);
    }

    /* Tx Power is from +5 to +23 dbm */
    rf95.setTxPower(23);
    /* There are different configurations
     * you can find in lib/radiohead/RH_RF95.h 
     * at line 437 
     */
    rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128);
    rf95.setFrequency(868.0); /* MHz */

	mosqpp::lib_init();
	mqttPublisher = make_shared<MqttPublisher>("frequency_publisher", "localhost", 1883);

}

void LoRaServer::loop()
{
    if( rf95.available() ) 
    {
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);

        if (rf95.recv(buf, &len)) 
        {
            printf("from %d, number %d\n", buf[0], buf[1]);
            // mqttPublisher->on_publish("{ \"device\": \"arduino\", \"type\": \"temp\", \"value\": 26.4, \"unit\": \"°C\" }");
        }
    }
}

void LoRaServer::run()
{
    while(run)
    {
        loop();
        usleep(1);
    }
}

void LoRaServer::stop()
{
    run = 0;
    mosqpp::lib_cleanup();
}