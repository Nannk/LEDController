#pragma once

#include <NTPClient.h>
#include <WiFiUdp.h>

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");


void NTPSetup() //Should be used after the  OTASetup
{
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(3600*2);
}


long NTPgetEpochTime()
{
    timeClient.update();
    return timeClient.getEpochTime();
}

String NTPgetFormattedTime()
{
    timeClient.update();
    return timeClient.getFormattedTime();
}

int NTPgetHour()
{
  return timeClient.getHours();
  timeClient.update();
}

int NTPgetMinute()
{
  timeClient.update();
  return timeClient.getMinutes();
}
  
int NTPgetSecond()
{
  timeClient.update();
  return timeClient.getSeconds();
}