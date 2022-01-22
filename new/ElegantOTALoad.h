#pragma once

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ElegantOTA.h>

#include <Configuration.h>
#include <EasyButton.h>

const char* ssid = "FRITZ!Box 7430 ZW";
const char* password = "24587448045534044941";

ESP8266WebServer server(80);
EasyButton button(BUTTON_PIN);


void OTAsetup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  pinMode(D0, OUTPUT);
  
  digitalWrite(D0, HIGH);
  button.begin();

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  digitalWrite(D0, LOW);
  delay(100);
  digitalWrite(D0, HIGH);
  delay(200);
  digitalWrite(D0, LOW);
  delay(100);
  digitalWrite(D0, HIGH);
  delay(500);

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/plain", "Hi! I am ESP8266.");
  });

  ElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  Serial.println("HTTP server started");
}

void OTAloop(void) {
    button.read();
    if(button.isPressed())
    {
      while(true)
      {
        server.handleClient();
      }
    }
}