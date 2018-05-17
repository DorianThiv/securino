# securino

## Getting Started

Clone project
```
git clone --recursive https://github.com/DorianThiv/securino.git
```

Install npm packages from packages.json
```
npm install
```

"wsserver.js" is a MQTT client. It send messages on TCP websocket.
In this file there is a simple list (TOPICS). She contains the topics to subscribe.
Change topics to subscribe on others.
Launch server "MQTT to TCP"
```
node wsserver.js
```
"wsclient.js" contain the url for the TCP socket. 
Launch client side in browser
```
firefox index.html
```

Launch cpp "MQTT publisher"
You have to compile mosquitto library to have libmosquitto.so
```
cd lib/mosquitto
make
cd ..
```

```
cd cpp/
make all
./securino_frequency_to_mqtt
```

