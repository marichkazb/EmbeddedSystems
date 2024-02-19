// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 4
// Exercise 2
// Submission code:  (provided by your TA-s)

// AVR Timer CTC Interrupts Calculator
// v. 8
// http://www.arduinoslovakia.eu/application/timer-calculator
// Microcontroller: ATmega328P
// Created: 2024-02-19T15:42:07.266Z

// include servo library
#include <Servo.h>

// declare variable to hold seconds
const int secPin = 2;  // Pin for the seconds servo
const int minPin = 10; // Pin for the optional minutes servo

Servo secondsServo; // Servo entity for seconds
Servo minutesServo; // Servo entity for minutes

volatile int seconds = 0; // initialize seconds counter
volatile int minutes = 0; // initialize minutes counter
volatile int tics = 0;    // initialize tics counter

// function to move seconds servo by the num in the counter
void moveServoSec(int num)
{
    // mapping function translates the range of seconds that can be 0-59
    // to the range of servi that is 0 to 180
    int mappedAngle = map(num, 0, 59, 0, 180);
    // rotate servo by the given value
    secondsServo.write(mappedAngle);
    // wait for 15ms
    delay(15);
}

// function to move minutes servo by the num in the counter
void moveServoMin(int num)
{
    // mapping function translates the range of seconds that can be 0-59
    // to the range of servi that is 0 to 180
    int mappedAngle = map(num, 0, 59, 0, 180);
    // rotate servo by the given value
    minutesServo.write(mappedAngle);
    // wait for 15ms
    delay(15);
}

// set up function is executed when starting the program
void setup()
{
    // initialize the serial monitor
    Serial.begin(9600);
    // function to set up the timer2.
    // we need to use timer 2 so that is doesn't intersect with servo tasks
    setupTimer2();
    // initialize seconds servo with the pin values
    secondsServo.attach(secPin);
    // initialize minutes servo with the pin values
    minutesServo.attach(minPin);
}

// empty loop body, since we execute everything in interrupts on timer function
void loop()
{
}

// setupTimer2 function, source code from:
// http://www.arduinoslovakia.eu/application/timer-calculator
// code defined in the function scope is our original work
ISR(TIMER2_COMPA_vect)
{
    // increment tics since the function is triggered every millisecond
    tics++;
    // if we reached 1 second counter
    if (tics == 1000)
    {
        // increment seconds
        seconds++;
        // set tics back to 0
        tics = 0;
        // move servo that is responsible for seconds timer by one second
        moveServoSec(seconds);
        // if seconds reached 1 min
        if (seconds == 60)
        {
            // set seconds back from start
            seconds = 0;
            // increment minutes counter
            minutes++;
            // if minutes reached 60
            if (minutes == 60)
            {
                // set minutes back to start
                minutes = 0;
            }
            // move servo responsible for minutes when the counter is incremented
            moveServoMin(minutes);
        }
        // print the values of min and sec to the serial monitor
        Serial.print("min: ");   // print user message
        Serial.print(minutes);   // print minutes value
        Serial.print(" sec: ");  // print user message
        Serial.println(seconds); // print seconds value
    }
}

// setupTimer2 function, source code from:
// http://www.arduinoslovakia.eu/application/timer-calculator
void setupTimer2()
{
    // start the function body
    noInterrupts();
    // Clear registers
    TCCR2A = 0; // Clear register
    TCCR2B = 0; // Clear register
    TCNT2 = 0;  // Clear register

    // 1000 Hz (16000000/((124+1)*128))
    OCR2A = 124;
    // CTC
    TCCR2A |= (1 << WGM21);
    // Prescaler 128
    TCCR2B |= (1 << CS22) | (1 << CS20);
    // Output Compare Match A Interrupt Enable
    TIMSK2 |= (1 << OCIE2A);
    // call the main function interrupts
    interrupts();
}
