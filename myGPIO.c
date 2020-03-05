/*
 * GPIO.c
 *
 *  Created on 3/4/2020 :
 *      Author Mouad ait taleb ali:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"
#define L1 BIT1
#define L2 BIT4
#define B1 BIT1
#define B2 BIT5
#define red_LED_1   BIT0
#define red_LED_2   BIT0
#define green_LED_2 BIT1
#define blue_LED_2  BIT2
#define red_BLED    BIT6
#define green_BLED  BIT4
#define blue_BLED   BIT6
#define PRESSED 0


// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
    // Launchpad S1
    void int_Launchpad_button_s1()
    {
        P1DIR &= ~L1 ;
        P1REN |=  L1 ;
        P1OUT |=  L1 ;
    }

  // Launchpad S2
    void int_Launchpad_button_s2()
    {
        P1DIR &= ~L2;
        P1REN |= L2;
        P1OUT |= L2;
    }
    // Boosterpack S1

    void int_Boosterpack_button_s1()
    {
        P5DIR &= ~B1;
        P5REN |= B1;
        P5OUT |= B1;
    }

    // Boosterpack S2
    void int_Boosterpack_button_s2()
    {
        P3DIR &= ~B2;
        P3REN |= B2;
        P3OUT |= B2;
    }

    // Launchpad LED1
    void int_Launchpad_red_LED_1()
    {
        P1DIR = P1DIR | red_LED_1;

    }

    // Launchpad LED2 Red
    void int_Launchpad_red_LED_2()
    {
        P2DIR |= red_LED_2;

    }

    // Launchpad LED2 Green
    void int_Launchpad_green_LED_2()
    {
        P2DIR |= green_LED_2;

    }

    // Launchpad LED2 Blue
    void int_Launchpad_blue_LED_2()
    {
        P2DIR |= blue_LED_2;

    }

    // Boosterpack LED Red
    void int_Boosterpack_red_LED()
    {
        P2DIR |= red_BLED;

    }


    // Boosterpack LED Green

    void int_Boosterpack_green_LED()
    {
        P2DIR |= green_BLED;

    }

    // Boosterpack LED Blue
    void int_Boosterpack_blue_LED()
    {
        P5DIR |= blue_BLED;
    }
void initGPIO()
{
    // Launchpad S1
    void int_Launchpad_button_s1();

  // Launchpad S2
    void int_Launchpad_button_s2();

    // Boosterpack S1

    void int_Boosterpack_button_s1();

    // Boosterpack S2
    void int_Boosterpack_button_s2();

    // Launchpad LED1
    void int_Launchpad_red_LED_1();

    // Launchpad LED2 Red
    void int_Launchpad_red_LED_2();

    // Launchpad LED2 Green
    void int_Launchpad_green_LED_2();

    // Launchpad LED2 Blue
    void int_Launchpad_blue_LED_2();

    // Boosterpack LED Red
    void int_Boosterpack_red_LED();

    // Boosterpack LED Green
    void int_Boosterpack_green_LED();

    // Boosterpack LED Blue
    void int_Boosterpack_blue_LED();

}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & L1 ) != PRESSED);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & L2 ) != PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & B1 ) == PRESSED);

}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & B2 ) == PRESSED);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1DIR = P1DIR | red_LED_1;
    P1OUT = P1OUT | red_LED_1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1DIR = P1DIR | red_LED_1;
    P1OUT = P1OUT & ~red_LED_1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2DIR |= red_LED_2;
    P2OUT = P2OUT | red_LED_2;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2DIR |= red_LED_2;
    P2OUT = P2OUT & ~red_LED_2;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{

    P2DIR |= green_LED_2;
    P2OUT = P2OUT | green_LED_2;

}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2DIR |= green_LED_2;
    P2OUT = P2OUT & ~green_LED_2;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{

    P2DIR |= blue_LED_2;
    P2OUT = P2OUT | blue_LED_2;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{

    P2DIR |= blue_LED_2;
    P2OUT = P2OUT & ~blue_LED_2;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2DIR |= red_BLED;
    P2OUT = P2OUT | red_BLED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2DIR |= red_BLED;
    P2OUT = P2OUT & ~red_BLED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{

    P2DIR |= green_BLED;
    P2OUT = P2OUT | green_BLED;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2DIR |= green_BLED;
    P2OUT = P2OUT & ~green_BLED;

}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{

    P5DIR |= blue_BLED;
    P5OUT = P5OUT | blue_BLED;

}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5DIR |= blue_BLED;
    P5OUT = P5OUT & ~blue_BLED;
}
