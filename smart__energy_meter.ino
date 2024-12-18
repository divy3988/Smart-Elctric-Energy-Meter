#include "ACS712.h"
#include <WiFi.h>
const char* ssid = "";
const char* password = "";
String header;
WiFiServer server(45);
ACS712 ACS(25, 5.0, 1023, 100);
void setup()
{
 Serial.begin(115200);
 while (!Serial);
 Serial.println(_FILE_);
 Serial.print("ACS712_LIB_VERSION: ");
 Serial.println(ACS712_LIB_VERSION);
 ACS.autoMidPoint();
 Serial.print("MidPoint: ");
 Serial.println(ACS.getMidPoint());
 PAGE 7
 Serial.print("Noise mV: ");
 Serial.println(ACS.getNoisemV());
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }

 //Serial.println("");
 //Serial.println("WiFi connected.");
 //Serial.println("IP address: ");
 //Serial.println(WiFi.localIP());
 server.begin();
 pinMode(26, INPUT);
}
void loop()
{
 float average = 0;
 uint32_t start = millis();
 for (int i = 0; i < 100; i++)
 PAGE 8
 {
 // select sppropriate function
 // average += ACS.mA_AC_sampling();
 average += ACS.mA_AC();
 // Serial.println(ACS.mA_AC());
 // delay(1000);
 }
 float mA = average / 100.0;
 mA=mA/1000;
 // uint32_t duration = millis() - start;
 Serial.print(" Ampere current: ");
 Serial.println(mA);
 // Read analog input
 float voltage=analogRead(26)/1000;
 Serial.print(" volts ");
 Serial.println(voltage);
 float power=(mA*voltage);
 Serial.println(power);
 WiFiClient client = server.available();
 if (client) {
 currentTime = millis();
 PAGE 9
 previousTime = currentTime;
 Serial.println("New Client.");
 String currentLine = "";
 while (client.connected() && currentTime - previousTime <=
timeoutTime) {
 currentTime = millis();
 if (client.available()) {
 char c = client.read();
 Serial.write(c);
 header += c;
 if (c == '\n') {

 if (currentLine.length() == 0) {
 client.println("HTTP/1.1 200 OK");
 client.println("Content-type:text/html");
 client.println("Connection: close");
 client.println();
 client.println("<!DOCTYPE html><html>");
 client.println("<head><meta name=\"viewport\"
content=\"width=device-width, initial-scale=1\">");
 client.println("<link rel=\"icon\" href=\"data:,\">");
 client.println("<body><h1>Smart Energy Meter </h1>");
 client.println("<p>Current :" + mA + "</p>");
 PAGE 10
 client.println("<p> Voltage :" + voltage + "</p>");
 client.println("<p> Power :" + power + "</p>");
 break;
 } else {
 currentLine = "";
 }
 } else if (c != '\r') {
 currentLine += c;
 }
 }
 }
 header = "";
 client.stop();
 Serial.println("Client disconnected.");
 Serial.println("");
 }
} 