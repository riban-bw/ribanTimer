#include <Arduino.h>
#include <ribanTimer/ribanTimer.h>

/*
  Use non-blocking timer as switch debounce
  Toggles an LED when a button is pressed

  D10 x------/ ------x Gnd

  D13 x--[ 1K ]-->|--x Gnd

  This example code is in the public domain.
*/

static const int PIN_LED = 13; // Pin 13 has an LED connected on most Arduino boards
static const int PIN_SWITCH = 10; //Switch connected between pin 10 and ground
Timer timerDebounce; //Instantiate a timer to handle debounce
bool g_bState; // State of output (LED 13)
bool g_bButtonReleased; //True if the button is released

void setup()
{
	pinMode(PIN_LED, OUTPUT); // initialize the digital pin as an output
	pinMode(PIN_SWITCH, INPUT_PULLUP); // initialize the digital pin as an input with pullup
}

void loop()
{
    if(timerDebounce.IsRunning() == false)
    {
        //Debounce timer not running so outside debounce period
        bool bState = digitalRead(PIN_BUTTON); //Get current input value
        if(g_bButtonReleased != bState)
        {
            //Button state has changed
            g_bButtonReleased = bState;
            timerDebounce.start(50, true); //Start one-shot timer for 50ms to provide 50ms hold-off (debounce)
            if(!g_bButtonReleased)
            {
                //Button has been pressed so toggle LED
                bState = digitalRead(PIN_LED); //Reuse bState, assigning the current LED state
                digitalWrite(PIN_LED, !bState); //Invert LED
            }
        }
    }
}
