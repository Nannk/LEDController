#include <Arduino.h>

#include <LedControl.h>
#include <OTAload.h>
#include <Configuration.h>
#include <superserver.h>


void setup() 
{
  OTAsetup();
  LEDSetup();
  OTAhandle();
  superserversetup();
}

void loop() 
{
  superserverexe();

  switch (mode)
  {
  case 0:
    SolidLine();
    break;

  case 1:
    MovingLine();
    break;

  case 2:
    EpilepsyWarning();
    break;
  
  case 3:
    SunAnimation();
    break;
  
  case 4:
    OTAhandleNoButton();
    break;

  case 10:
    LightsOff();
    break;
  
  default:
    OTAhandleNoButton();
    break;
  }
}