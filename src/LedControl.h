#pragma oncees

#include <FastLED.h>
#include <Configuration.h>

CRGB leds[LED_NUM];

int k; //counters
int t;

void LEDSetup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, GRB>(leds, LED_NUM);
    FastLED.clear();
    FastLED.setBrightness(Brightness);
}

void MovingLine()
{
    k=0;
    while(k<=LED_NUM)
    {
       leds[k] = CRGB::White;
       k++;
       FastLED.show();
       delay(leddelay);
    }
    while(k>0)
    {
       leds[k] = CRGB::Black;
       k--;
       FastLED.show();
       delay(leddelay);
    }
}

void SolidLine()
{
    k=0;
    while(k<=LED_NUM)
    {
        leds[k].setRGB(ValueRed,ValueGreen,ValueBlue);
        k++;
    }

    FastLED.setBrightness(Brightness);
    FastLED.show();
    delay(1000);
}

void EpilepsyWarning()
{
    k=0;
    while(k<LED_NUM)
    {
        int r = rand()%255;
        int g = rand()%255;
        int b = rand()%255;
        leds[k].setRGB( r, g, b);
        FastLED.setBrightness(rand()%255);
        k++;
    }
    FastLED.show();
    delay(EpilepsyDelay);
}

void SunAnimation()
{
    for(int c0 =0 ; c0<LED_NUM; c0++)
        {
            leds[c0] = CRGB::Red;
        }

    for(int c1=0; c1<Brightness; c1++)
    {
        FastLED.setBrightness(c1);
        FastLED.show();
        delay(IterationTime);
    }
    
    for(int c2 =0; c2<Iterations; c2++)
    {
        for(int c3 =0 ; c3<LED_NUM; c3++)
        {
            int r = 255- ((c2*255)/(3*Iterations));
            int g = (c2*255)/(2*Iterations);
            int b = (c2*255)/Iterations;
            leds[c3].setRGB( r, g, b);
        }
        FastLED.show();
        delay(IterationTime);
    }

    while(true)
    {
        delay(10000);
    }
}

void LightsOff()
{
    k=0;
    while(k<=LED_NUM)
    {
        leds[k].setRGB(0,0,0);
        k++;
    }

    FastLED.setBrightness(0);
    FastLED.show();
    delay(1000);
}