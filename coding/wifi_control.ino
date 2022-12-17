#include<SoftwareSerial.h>
#include <WiFiNINA.h>
SoftwareSerial SUART(10,11);

char ssid[] = "smarthome";        
char pass[] = "projecttest";     
int keyIndex = 0;                 
int status = WL_IDLE_STATUS;      //connection status
WiFiServer server(80);            //server socket

WiFiClient client = server.available();


void setup() {
  Serial.begin(9600);
  SUART.begin(9600);
  while (!Serial);
  
  enable_WiFi();
  connect_WiFi();

  server.begin();
  printWifiStatus();

}

void loop() {
  client = server.available();

  if (client) {
    printWEB();
  }
  if (SUART.available()>0){
    if (client){
      client.print("ALERT: Intruder detected!");
    }
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");

  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}

void enable_WiFi() {
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
    Serial.println("Please upgrade the firmware");
  }
}

void connect_WiFi() {
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
}

void printWEB() {

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {

            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
           
            //create the buttons
            client.print("Switch 1 <a href=\"/A\">ON</a> <a href=\"/a\">OFF</a><br>");
            client.print("Switch 2 <a href=\"/B\">ON</a> <a href=\"/b\">OFF</a><br>");
            client.print("Switch 3 <a href=\"/C\">ON</a> <a href=\"/c\">OFF</a><br>");
            client.print("Switch 4 <a href=\"/D\">ON</a> <a href=\"/d\">OFF</a><br>");
            client.print("Switch 5 <a href=\"/E\">ON</a> <a href=\"/e\">OFF</a><br>");
            client.print("Switch 6 <a href=\"/F\">ON</a> <a href=\"/f\">OFF</a><br>");
            client.print("Switch 7 <a href=\"/G\">ON</a> <a href=\"/g\">OFF</a><br>");
            client.print("Switch 8 <a href=\"/H\">ON</a> <a href=\"/h\">OFF</a><br>");
            client.print("Switch 9 <a href=\"/I\">ON</a> <a href=\"/i\">OFF</a><br>");
            
            int randomReading = analogRead(A1);
            client.print("Random reading from analog pin: ");
            client.print(randomReading);
           
            
            

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        if (currentLine.endsWith("GET /A")) { //light1
        SUART.write("A");
        }
        if (currentLine.endsWith("GET /a")) {
        SUART.write("a");       
        }
        if (currentLine.endsWith("GET /B")) { //light2
        SUART.write("B");       
        }
        if (currentLine.endsWith("GET /b")) {
        SUART.write("b");        
        }
        if (currentLine.endsWith("GET /C")) {//light3
        SUART.write("C");       
        }
        if (currentLine.endsWith("GET /c")) {
        SUART.write("c");       
        }
        if (currentLine.endsWith("GET /D")) {//light4
        SUART.write("D");       
        }
        if (currentLine.endsWith("GET /d")) {
        SUART.write("d");      
        }
        if (currentLine.endsWith("GET /E")) {//light5
        SUART.write("E");       
        }
        if (currentLine.endsWith("GET /e")) {
        SUART.write("e");      
        }
        if (currentLine.endsWith("GET /F")) {//light6
        SUART.write("F");       
        }
        if (currentLine.endsWith("GET /f")) {
        SUART.write("f");      
        }
        if (currentLine.endsWith("GET /G")) {//light7
        SUART.write("G");       
        }
        if (currentLine.endsWith("GET /g")) {
        SUART.write("g");      
        } 
        if (currentLine.endsWith("GET /H")) {//light8
        SUART.write("H");       
        }
        if (currentLine.endsWith("GET /h")) {
        SUART.write("h");      
        }
        if (currentLine.endsWith("GET /I")) {//light9
        SUART.write("I");       
        }
        if (currentLine.endsWith("GET /i")) {
        SUART.write("i");      
        }                       

      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}