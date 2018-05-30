/**
 * Securino Transferts Server (SecurinoTS)
 * 
 * This Nodejs module call too external modules (mqtt, websocket).
 * It provide a MQTT client which will subscribe to a mqtt topic (ex: 'presence')
 * and receive messages from local MQTT Broker (mosquitto). The message will be send over a websocket
 * and receive by a tcp client.
 * 
 * JSON Fromat for mqtt message: { device: '', sensor: '', value: '', unit: '' }
 * 
 * MQTT ---- TCP-SRV ---- TCP-CLI
 * 
 * MQTT.js library: https://github.com/mqttjs/MQTT.js.git
 * 
 * Git: https://github.com/DorianThiv/securino.git
 * 
 */

const URL_PROTOCOLE = 'mqtt://';
const URL_HOST = '192.168.0.17';
const URL_PORT = 1337;

const TOPICS = [
    'arduino/temp',
    'arduino/humidity',
    'arduino/alarms/lasers'
];

var http = require('http');
var mqtt = require('mqtt');
var WebSocketServer = require('websocket').server;

var mqttcli = mqtt.connect(URL_PROTOCOLE + URL_HOST);

mqttcli.on('connect', function () {
    console.log('SECURINO-MQTT (connected)');
    TOPICS.forEach(function(topic) {
        mqttcli.subscribe(topic);
    });
});

var server = http.createServer(function(request, response) {
    console.log('SECURINO-TCP (running)')
});

server.listen(URL_PORT, URL_HOST);

wsServer = new WebSocketServer({
    httpServer: server
});

wsServer.on('request', function(request) {
    var connection = request.accept(null, request.origin);
    console.log('SECURINO-TCP client accepted');

    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log('SECURINO-TCP Receive message : ' + message.utf8Data);
        } else {
            console.log('SECURINO-TCP Receive a none utf-8 encoding');
        }
    });

    mqttcli.on('message', function (topic, message) {
        console.log('SECURINO-MQTT Receive message : ' + message.toString());
        connection.sendUTF(message);
    });

    connection.on('close', function(connection) {
        console.log('SECURINO-TCP client disconnected');
    });
});
