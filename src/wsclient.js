
var wsUri = "ws://192.168.0.18:1337/";

var state;
var error;

var tempDevice;
var tempSensor;
var tempValue;
var tempUnit;

var humiDevice;
var humiSensor;
var humiValue;
var humiUnit;

var lazerDevice;
var lazerSensor;
var lazerValue;
var lazerUnit;

function init() {
    state = $('#state');
    error = $('#error');

    tempDevice = $('#temp-device');
    tempSensor = $('#temp-sensor');
    tempValue = $('#temp-value');
    tempUnit = $('#temp-unit');

    lazerDevice = $('#lazer-device');
    lazerSensor = $('#lazer-sensor');
    lazerValue = $('#lazer-value');
    lazerUnit = $('#lazer-unit');

    humiDevice = $('#humi-device');
    humiSensor = $('#humi-sensor');
    humiValue = $('#humi-value');
    humiUnit = $('#humi-unit');

    connect();
}

function connect() {
    websocket = new WebSocket(wsUri);
    
    websocket.onopen = function(event) {
        onOpen(event)
    };
    
    websocket.onclose = function(event) {
        onClose(event)
    };
    
    websocket.onmessage = function(event) {
        onMessage(event)
    };
    
    websocket.onerror = function(event) {
        onError(event)
    };
}

function onOpen(event) {
    writeState("CONNECTED");
    send("Securino web app connected");
}

function onClose(event) {
    writeState("DISCONNECTED");
}

function onMessage(event) {
    console.log(event);
    if (event !== undefined) {
        try {
            var dataJson = JSON.parse(event.data);
            if (dataJson !== undefined) {
                switch (dataJson.sensor) {
                    case "temperature":
                        writeTemp(dataJson);
                        break;
                    case "humidity":
                        writeHumi(dataJson);
                        break;
                    case "lazer":
                        writeLazer(dataJson);
                        break;
                    default:
                        writeError('<span style = "color: red;">ERROR : Unknow sensor ...</span>');
                        break;
                }
            }
        } catch (error) {
            writeError('<span style = "color: red;">ERROR : ' + error + '</span>');
        }
    } else {
        writeError('<span style = "color: red;">ERROR event is undefined : ' + event + '</span>');
    }
}

function onError(event) {
    writeState('<span style = "color: red;">ERROR:</span> ' + event.data);
} 
          
function send(message) {
   websocket.send(message);
}

function close() {
    websocket.close();
}

function writeState(message) {
    state.html(message);
}

function writeTemp(message) {
    tempDevice.html(message.device);
    tempSensor.html(message.sensor);
    tempValue.html(message.value);
    tempUnit.html(message.unit);
}

function writeHumi(message) {
    humiDevice.html(message.device);
    humiSensor.html(message.sensor);
    humiValue.html(message.value);
    humiUnit.html(message.unit);
}

function writeLazer(message) {
    lazerDevice.html(message.device);
    lazerSensor.html(message.sensor);
    lazerValue.html(message.value);
    lazerUnit.html(message.unit);
}

function writeError(message) {
    error.html(message);
}

window.addEventListener("load", init, false);