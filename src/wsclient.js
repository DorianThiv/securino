
var wsUri = "ws://127.0.0.1:1337/";
var output;

function init() {
    output = document.getElementById("output");
    connect();
}

function connect() {
    websocket = new WebSocket(wsUri);
    
    websocket.onopen = function(evt) {
        onOpen(evt)
    };
    
    websocket.onclose = function(evt) {
        onClose(evt)
    };
    
    websocket.onmessage = function(evt) {
        onMessage(evt)
    };
    
    websocket.onerror = function(evt) {
        onError(evt)
    };
}

function onOpen(evt) {
    writeToScreen("CONNECTED");
    doSend("Securino web app connected");
}

function onClose(evt) {
    writeToScreen("DISCONNECTED");
}

function onMessage(evt) {
    if (evt !== undefined) {
        try {
            var dataJson = JSON.parse(evt.data);
            if (dataJson !== undefined) {
                writeToScreen(
                    '<div style = "background-color: green; color: white; width: 300px; padding: 20px">' + 
                    '<p>Device : ' + dataJson.device + '</p>' +
                    '<p>Sensor : ' + dataJson.type + '</p>' +
                    '<p>Value : ' + dataJson.value + ' ' + dataJson.unit + '</p>' +
                    '</div>');
            }
        } catch (error) {
            writeToScreen('<span style = "color: red;">ERROR : ' + error + '</span>');
        }
    } else {
        writeToScreen('<span style = "color: red;">ERROR event is undefined : ' + evt + '</span>');
    }
}

function onError(evt) {
    writeToScreen('<span style = "color: red;">ERROR:</span> ' + evt.data);
} 
          
function doSend(message) {
    writeToScreen("SENT: " + message); websocket.send(message);
}

function doClose() {
    websocket.close();
}

function writeToScreen(message) {
    var pre = document.createElement("p"); 
    pre.style.wordWrap = "break-word"; 
    pre.innerHTML = message; 
    output.appendChild(pre);
}

window.addEventListener("load", init, false);