CFLAGS=-std=c++11 -Wall -ggdb -I../../lib/mosquitto/lib -I../../lib/mosquitto/lib/cpp
LDFLAGS=-L../../lib/mosquitto/lib ../../lib/mosquitto/lib/cpp/libmosquittopp.so.1 ../../lib/mosquitto/lib/libmosquitto.so.1

.PHONY: all clean

all : securino_frequency_to_mqtt

securino_frequency_to_mqtt : main.o MqttPublisher.o
	${CXX} $^ -o $@ ${LDFLAGS}

main.o : main.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

MqttPublisher.o : MqttPublisher.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

clean : 
	-rm -f *.o securino_frequency_to_mqtt
