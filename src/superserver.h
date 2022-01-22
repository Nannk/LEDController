#pragma once

#include <Arduino.h>
#include <Configuration.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <index.h>

ESP8266WebServer superserver(80);

void handleroot()
{
    superserver.send(200, "text/html", index_html);
}

void handlesldline()
{
    //#define MODE 0
    mode = 0;
    superserver.send(200, "text", "Solid Line");
}

void handlemovline()
{
    //#define MODE 1 
    mode = 1;
    superserver.send(200, "text", "Moving Line");
}

void handleepilepsy()
{
    //#define MODE 2
    mode = 2;
    superserver.send(200, "text", "Epilepsy Mode");
}

void handlesunmode()
{
    //#define MODE 3
    mode = 3;
    superserver.send(200, "text", "Sun Mode");
}

void handleflash()
{
    //#define MODE 4
    mode = 4;
    superserver.send(200, "text", "Flash Mode");
}

void handlelightsoff()
{
    mode = 10;
    superserver.send(200, "text", "Lights OFF");
}


void superserversetup()
{
    superserver.on("/", handleroot);

    superserver.on("/sldline",  handlesldline);
    superserver.on("/movline", handlemovline);
    superserver.on("/epilepsy", handleepilepsy);
    superserver.on("/sunmode", handlesunmode);
    superserver.on("/flash", handleflash);
    superserver.on("/off", handlelightsoff);


    superserver.begin();
}

void superserverexe()
{
    superserver.handleClient();
}
