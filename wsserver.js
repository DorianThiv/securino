const URL_PROTOCOLE = 'mqtt://';
const URL_HOST = '127.0.0.1';
const URL_PORT = 1337;

var http = require('http');
var mqtt = require('mqtt');
var WebSocketServer = require('websocket').server;

var mqttcli = mqtt.connect(URL_PROTOCOLE + URL_HOST);

mqttcli.on('connect', function () {
    mqttcli.subscribe('presence');
});

var server = http.createServer(function(request, response) {
    // console.log('TCP Server ...');
});
server.listen(URL_PORT, URL_HOST);

// create the server
wsServer = new WebSocketServer({
    httpServer: server
});

// WebSocket server
wsServer.on('request', function(request) {
    var connection = request.accept(null, request.origin);

    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log('TCP Message : ' + message.utf8Data);
        }
    });

    mqttcli.on('message', function (topic, message) {
        connection.sendUTF(message);
    });

    connection.on('close', function(connection) {
        console.log('TCP client disconnect');
    });
});