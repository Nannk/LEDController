#pragma once

//#include <ESP8266WiFi.h>
//#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer superserver(80);

const char* RED_INPUT = "VRed";
const char* GREEN_INPUT = "VGreen";
const char* BLUE_INPUT = "VBlue";
const char* BRIGHTNESS_INPUT = "VBrightness";

const char* MODE_INPUT = "radio-modes";

const char index_html[] PROGMEM = R"rawliteral(
<!//html code here>
)rawliteral";

void notFound (AsyncWebServerRequest *request)
{
    request->send(404, "text/plain","Not found");
}

void serverset(void)//Should be exec after WIfI Setup
{
    superserver.on("/", HTTP_GET,[](AsyncWebServerRequest *request)
    {
        request->send_P(200, "text/html", index_html);
    });

    superserver.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) 
    {
        String inputMessage;
        String inputRed;
        String inputGreen;
        String inputBlue;
        String inputBrightness;
        String inputMode;


        if(request->hasParam(RED_INPUT))
        {
            inputMessage=request-> getParam(RED_INPUT)->value();
            inputRed = RED_INPUT;
        }

        if(request->hasParam(RED_INPUT))
        {
            inputMessage=request-> getParam(GREEN_INPUT)->value();
            inputGreen= GREEN_INPUT;
        }

        if(request->hasParam(BLUE_INPUT))
        {
            inputMessage=request-> getParam(BLUE_INPUT)->value();
            inputBlue = BLUE_INPUT;
        }

        if(request->hasParam(BRIGHTNESS_INPUT))
        {
            inputMessage=request-> getParam(BRIGHTNESS_INPUT)->value();
            inputBrightness = BRIGHTNESS_INPUT;
        }

         if(request->hasParam(MODE_INPUT))
        {
            inputMessage=request-> getParam(MODE_INPUT)->value();
            inputMode = MODE_INPUT;
        }

    });
    superserver.onNotFound(notFound);
    superserver.begin();
}

