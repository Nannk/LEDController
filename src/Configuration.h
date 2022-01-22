#pragma once

//Led Strip
#define LED_NUM 56
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define LED_PIN D4      //Number Only?

//RGB Values
#define ValueRed 255
#define ValueGreen 180
#define ValueBlue 180
//Brigthess
#define Brightness 123
#define leddelay 100

    //Epilepsy Mode
#define EpilepsyDelay 100 
#define EpilepsyBrightness 200

    //Sun Mode
#define Iterations 255
#define IterationTime 10000

//Server

//Modes
int mode = 10;
//#define MODE 1
//Mode 0 - Running line Mode

//#define SCL_PIN D1 
//#define SDA_PIN D2  //<-- Thats how the pins are hardwired
//#define TEMP_PIN D8  //DS Pin on TinyRTC


//Networking
//const char* ssid = "FRITZ!Box 7430 ZW"; // "FRITZ!Box 7430 ZW"
//const char* password = "24587448045534044941"; // "24587448045534044941"
// "esp8266"
//IP: 192.168.178.37

//UDP
//#define UDPPORT 22151
//#define HOSTIP "192.168.178.100"

//sonstiges
#define BaudRate 9600
#define BUTTON_PIN D3