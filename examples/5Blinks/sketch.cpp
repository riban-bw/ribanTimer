#include <Arduino.h>
#include <ribanTimer.h>

/*
  Use non-blocking timer to blink LED every second then stop after 5

  This example code is in the public domain.
*/

static const int g_nLedPin = 13; // Pin 13 has an LED connected on most Arduino boards
Timer timer1; // Instantiate a timer
Timer timer2; // Instantiate a timer
bool g_bToggle; // Toggles every second

void setup()
{
	pinMode(g_nLedPin, OUTPUT); // initialize the digital pin as an output.
	timer1.start(1000); // Start timer with 1 second period / interval
	timer2.start(5000, true); // Start one-shot timer with 5 second period / interval
}

void loop()
{
    if(timer1.IsTriggered())
    {
        // One second timer has triggered
        digitalWrite(g_nLedPin, g_bToggle); // Set LED state
        g_bToggle = !g_bToggle; // Toggle flag
    }
    if(timer2.IsTriggered())
    {
        // One shot timer has triggered
        timer1.stop(); // Stop the 1 second timer
        digitalWrite(g_nLedPin, LOW); // Turn off LED
    }
}
