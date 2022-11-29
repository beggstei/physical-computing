/* jshint esversion: 8 */

let serial; // the Serial object
let serialOptions = { baudRate:9600 };
let col;
let dn = "DAY";
let buttonConnect,buttonDisconnect;
let easing = 0.1;


function setup() {
  createCanvas(400, 400);
  //background(lerpColor(color1, color2, pos));
  // Setup Web Serial using serial.js
  serial = new Serial();
  serial.on(SerialEvents.CONNECTION_OPENED, onSerialConnectionOpened);
  serial.on(SerialEvents.CONNECTION_CLOSED, onSerialConnectionClosed);
  serial.on(SerialEvents.DATA_RECEIVED, onSerialDataReceived);
  serial.on(SerialEvents.ERROR_OCCURRED, onSerialErrorOccurred);
 
  // Add in a lil <p> element to provide messages. This is optional
  msg = createP("");
  col = color(255,250,205);
  textSize(100);
  textAlign(CENTER, CENTER);
  textFont("Roboto");
  
  buttonConnect = createButton('Connect Port');
  buttonConnect.position(20,20);
  buttonConnect.mousePressed(connectPort);
  
  buttonDisconnect = createButton('Disonnect Port');
  buttonDisconnect.position(150,20);
  buttonDisconnect.mousePressed(disconnectPort);
}

async function connectPort() {
  if (!serial.isOpen()) {
    await serial.connectAndOpen(null, serialOptions);
  } else {
    serial.autoConnectAndOpenPreviouslyApprovedPort(serialOptions);
  }
}

async function disconnectPort() {
  if (serial.isOpen()) {
    serial.close();
  }
}

function draw() {
  //let targetPos = pos;
  //let dPos = targetPos - pos;
  //pos += dPos * easing;
  //background(lerpColor(color1, color2, pos));
  fill(col);
  //text(dn, width/2, height/2);
  circle(200, 200, pos);
}

function onSerialErrorOccurred(eventSender, error) {
  console.log("onSerialErrorOccurred", error);
}

function onSerialConnectionOpened(eventSender) {
  console.log("onSerialConnectionOpened");
}

function onSerialConnectionClosed(eventSender) {
  console.log("onSerialConnectionClosed");
}

function onSerialDataReceived(eventSender, newData) {
  let potVal = int(newData);
  msg.html("onSerialDataReceived: " + potVal);
  console.log("Received data from Arduino: " +potVal);
  pos = potVal;
  let targetPos = pos;
  let dPos = targetPos - pos;
  pos += dPos * easing;
  let color1 = color(100, 0, 255);
let color2 = color(255, 0, 100);
  let amount = map(pos, 0, 400, 0, 1);
  console.log("Received amaount " +amount);
  background(lerpColor(color1, color2, amount));
  circle(pos, pos, 30);
  
  /*
  if(potVal==1) {
    col = color(255,250,205);
    dn = "DAY";
  } else {
    col = color(0,0,200);
    dn = "NIGHT";
  }*/
  
}
