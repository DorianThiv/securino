
/************************************************************************
 *
 *                           LoRa to MQTT
 *
 *                          Dorian THIVOLLE
 *                      dorian_thivolle@orange.fr
 *                               CASIR
 *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <memory>

#include "LoRaServer.h"

using namespace std;

shared_ptr<LoRaServer> loraServer;

void sigint_handler(int signal)
{
	loraServer->stop();
}

int main(int argc, char *argv[])
{
	signal(SIGINT, sigint_handler);
	loraServer = make_shared<LoRaServer>();
	loraServer->run();
	return 0;
}

