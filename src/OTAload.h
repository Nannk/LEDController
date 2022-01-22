#pragma once

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <Configuration.h>
#include <EasyButton.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


EasyButton button(BUTTON_PIN);

void OTAsetup()
{
  const char* ssid = "FRITZ!Box 7430 ZW";
  const char* password = "24587448045534044941";
  pinMode(D0, OUTPUT);
  
  digitalWrite(D0, HIGH);
  button.begin();
  
  Serial.begin(BaudRate);
  Serial.println("Booting");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) 
      {
          Serial.println("Connection Failed! Rebooting...");
          ESP.restart();
      }
  digitalWrite(D0, LOW);
  delay(100);
  digitalWrite(D0, HIGH);
  delay(200);
  digitalWrite(D0, LOW);
  delay(100);
  digitalWrite(D0, HIGH);
  delay(500);

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword(loadPassword);

    ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });

  //ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    //Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  //});
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
}

void OTAhandle()
{
  button.read();
  if(button.isPressed())
  {
    while(true)
    {
      ArduinoOTA.handle();
      digitalWrite(D0,LOW);
      delay(50);
      digitalWrite(D0,HIGH);
      delay(50);
    }
  }
}

void OTAhandleNoButton()
{
      ArduinoOTA.handle();
      digitalWrite(D0,LOW);
      delay(50);
      digitalWrite(D0,HIGH);
      delay(50);
}