// (C) Joel Celén, group: 8__ (2024)
// Work package 4
// Exercise 2
// Submission code:  (provided by your TA-s)


// ---- Source code for interrupt timer ----

// AVR Timer CTC Interrupts Calculator
// v. 8
// http://www.arduinoslovakia.eu/application/timer-calculator
// Microcontroller: ATmega328P
// Created: 2024-02-18T18:13:38.571Z

// ------------------------------------------

// Includes section
#include <Servo.h>

// Define section
#define SEC_PIN 9 // Assign pin 9 to servo

// Global variable declaration
volatile int tick = 0;   // Counts the ticks
volatile int second = 0; // Mount of seconds passed
volatile int flag = 1;   // Flag to reverse servo direction
float angle = 180;       // Angle of the servo
Servo servo;             // Servo

// Set-up function
void setup()
{
  // Setup timer2
  setupTimer2();
  // Start serial monitor
  Serial.begin(9600);
  // Attach servo to designated pin
  servo.attach(SEC_PIN);
}

// Loop function
void loop()
{
}

// Function to advance the servo
void advanceServo()
{

  if (flag == 0) // If flag is false, rotate counter clockwise
  {
    // Set angle to angle + 6
    angle += 6;
  }
  else // If flag is true, rotate clockwise
  {
    // Set angle to angle -6
    angle -= 6;
  }

  // Move the servo to the calculated angle
  servo.write(angle);

  // Print the current angle
  Serial.print("Angle: ");
  Serial.print(angle);

  // Print the current second
  Serial.print(" Second: ");
  Serial.println(second);
}

// Interrupt function skeleton:
// https://www.arduinoslovakia.eu/application/timer-calculator
// Code defined within the function is out original work.
ISR(TIMER2_COMPA_vect)
{
  // Tick = tick +1
  tick++;

  // When tick reaches 1000, one second has passed
  if (tick > 1000)
  {
    // Reset tick counter
    tick = 0;
    // Increment second
    second++;
    // Call advance servo
    advanceServo();

    // Every 30 seconds
    if (second % 30 == 0)
    {
      // Toggle flag to tell servo to move in the other direction
      flag ^= 1;
    }
  }
}

// Setup for timed interrupt, source code from:
// https://www.arduinoslovakia.eu/application/timer-calculator
void setupTimer2()
{
  // Disable interrupts
  noInterrupts();
  // Clear registers
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  // 1000 Hz (16000000/((124+1)*128))
  OCR2A = 124;
  // CTC
  TCCR2A |= (1 << WGM21);
  // Prescaler 128
  TCCR2B |= (1 << CS22) | (1 << CS20);
  // Output Compare Match A Interrupt Enable
  TIMSK2 |= (1 << OCIE2A);
  // Re-enable interrupt
  interrupts();
}