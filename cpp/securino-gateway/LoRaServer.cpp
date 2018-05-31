
#include "LoRaServer.h"
#include "SecurinoDecoder.h"

RH_RF95 rf95;

LoRaServer::LoRaServer()
{
    running = 1;
    setup();
}

LoRaServer::~LoRaServer() {}

void LoRaServer::setup()
{
    wiringPiSetupGpio();

    if (!rf95.init()) 
    {
        fprintf(stderr, "Init failed\n");
        exit(1);
    }
    else
    {
        printf("[$] LoRa initialized\n");
    }

    rf95.setTxPower(23);
    rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128);
    rf95.setFrequency(868.0);

	mosqpp::lib_init();
	mqttPublisher = make_shared<MqttPublisher>("lora_publisher", "localhost", 1883);
    printf("[$] Wait for message ...\n");

}

void LoRaServer::loop()
{
    if( rf95.available() ) 
    {
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);
        char fbuf[RH_RF95_MAX_MESSAGE_LEN];

        if (rf95.recv(buf, &len))
        {
            printf("=> Receive Frame ============\n");
            printf("=> LoRa Message : ");
            int i = 0;
            while (i < len)
            {
                // sprintf(fbuf+i*2, "%02x", buf[i]);
                printf("0x%02x ", buf[i]);
                i++;
            }
            printf("\n");
            SecurinoDecoder::decode(fbuf, buf, len);
            mqttPublisher->on_publish(fbuf);
        }
    }
}

void LoRaServer::run()
{
    while(running)
    {
        loop();
        usleep(1);
    }
}

void LoRaServer::stop()
{
    running = 0;
    mosqpp::lib_cleanup();
}
