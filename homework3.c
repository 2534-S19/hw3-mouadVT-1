#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;


    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char history = 0xff;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
         if(timer0Expired())
         {
              count0 = (count0+1)%8;
         }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c

         if(timer1Expired())
         {
             history = (history << 1) | checkStatus_BoosterpackS1();
         }
        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
         bool check = fsmBoosterpackButtonS1(history);


        // TODO: If a completed, debounced button press has occurred, increment count1.
   if(check)
       {
       count1 = (count1+1)%8;
       }
 }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count0)
{
    switch (count0)
    {
    case 0:
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        break;
    case 1:
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Blue();
        break;
    case 2:
        turnOn_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 3:
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        break;
    case 4:
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Blue();
        break;
    case 5:
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 6:
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
        break;
    case 7:
        turnOff_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();

        break;

    }


}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count1)
{
    switch (count1)
    {
    case 0:
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDGreen();

        break;
    case 1:
        turnOn_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDRed();
        break;
    case 2:
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDRed();

        break;
    case 3:
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDRed();
        break;
    case 4:
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 5:
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDGreen();
        break;
    case 6:
        turnOn_BoosterpackLEDBlue();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDRed();
        break;
    case 7:
        turnOff_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDRed();
        break;

    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;
    static enum
    {
        up, down
    } intial_state = up;
    switch (intial_state)
    {
    case up:
        if (buttonhistory == 0xff)
        {
            intial_state = down;
            pressed = true;
        }
        break;
    case down:
        if (buttonhistory != 0xff)
        {
            intial_state = up;
            pressed = false;
        }
        break;

    }
    buttonhistory = intial_state;
    return pressed;
}
