#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>

#ifndef STASSID
#define STASSID "Galaxy S9+"
#define STAPSK "22222222"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const char* www_username = "RAYEN";
const char* www_password = "RAYEN";

const char* www_realm = "Custom Auth Realm";

String authFailResponse = "Authentication Failed";

void setup() {
  Serial.begin(9600);
  pinMode()
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Connect Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }
  ArduinoOTA.begin();

  server.on("/", []() {
    if (!server.authenticate(www_username, www_password))
    {
      return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
    }
    server.send(200, "text/plain", "Rayen you are the best");
  });
  server.begin();
  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
}
void loop() {
  ArduinoOTA.handle();
  server.handleClient();
}
void sell_blink(){
  digitalWrite(BUILTIN_LED,HIGH);
  delay(100);
  digitalWrite(BUILTIN_LED,LOW);
  delay(100);
}
