// (C) Joel Celén, group: 8__ (2024)
// Work package 4
// Exercise 1
// Submission code:  (provided by your TA-s)

// ---- Source code for interrupt timer ----

// ---- Source code for interrupt timer ----
// AVR Timer CTC Interrupts Calculator
// v. 8
// http://www.arduinoslovakia.eu/application/timer-calculator
// Microcontroller: ATmega328P
// Created: 2024-02-18T11:17:54.307Z

// ------------------------------------------

// Type definitions
typedef struct
{
  int threshold; // Temperature threshold value
  int state = 0; // Current state of the LED, initialized as off
  int pin;       // Assigned pin
} TEMP_LED;      // Name

// Function prototypes
void setupTimer1();                  // Set up function for timed interrupts
ISR(TIMER1_COMPA_vect);              // Interrupt protocol
void setLeds(TEMP_LED *ledArray);    // Set the states of the LEDs based on temperature
void assignLeds(TEMP_LED *ledArray); // Assign the LEDs
float convertCelsius();              // Converts analog reading from temp sensor to celsius

// Define section
#define TEMP_SENSOR A0 // Temperature sensor pin
#define ARRAY_SIZE 5   // Array to hold LEDs

// Global varibles
volatile int tempValue = 0;    // Stores analog reading
volatile int newReading = 0;   // Flag for indication of new reading
TEMP_LED ledArray[ARRAY_SIZE]; // Declare ledArray as a global variable
TEMP_LED *pLeds;               // Declare pLeds as a global variable

// Arduino setup function
void setup()
{
  setupTimer1();        // Call the function to set up Timer2
  Serial.begin(9600);   // Start serial
  pLeds = &ledArray[0]; // Set pointer to start of LED array
  assignLeds(pLeds);    // Assign LEDs
}

// Arduino loop function
void loop()
{
  // If there is a new reading
  if (newReading == 1)
  {
    // Set states of LEDs
    setLeds(pLeds);
    // Turn flag to false
    newReading = 0;
  }
}

// Interrupt function skeleton:
// https://www.arduinoslovakia.eu/application/timer-calculator
// Code defined within the function is out original work.
ISR(TIMER1_COMPA_vect)
{
  // Read temperature from sensor
  tempValue = analogRead(TEMP_SENSOR);
  // Turn flag to true to indicate new reading
  newReading = 1;
}

// Fucntion to assign the LEDs
void assignLeds(TEMP_LED *ledArray)
{
  // Starting pin
  int pin = 13;
  // Starting threshold value
  int threshold = 10;
  // For every LED
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    TEMP_LED temp;              // Temporary LED
    temp.threshold = threshold; // Set threshold
    temp.pin = pin;             // Set pin
    ledArray[i] = temp;         // Add LED to array
    pin--;                      // Decrement pin
    threshold += 10;            // Increment threshold by 10
  }
}

// Function that sets LEDs depending on temperature
void setLeds(TEMP_LED *ledArray)
{
  // Convert analog reading to celsius and sore in variable
  float temperature = convertCelsius();

  // For every LED in array
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    // If temperature exceeds threshold of LED at i
    if (temperature > ledArray[i].threshold)
    {
      // Turn on LED at i
      ledArray[i].state = 1;
    }
    // If temperature is below threshold of LED at i
    else
    {
      // Turn off LED at i
      ledArray[i].state = 0;
    }
    // Write current state of LED to display changes
    digitalWrite(ledArray[i].pin, ledArray[i].state);
  }
}

// Function to read temperature from a temperature sensor and convert to Celsius
float convertCelsius()
{

  // Convert the raw ADC value to voltage
  float voltage = tempValue * (5.0 / 1023.0);

  // Convert the voltage to celsius
  float temperatureCelsius = (voltage - 0.5) * 100.0;

  // Return value in celsius
  return temperatureCelsius;
}

// Setup for timed interrupt, source code from:
// https://www.arduinoslovakia.eu/application/timer-calculator
void setupTimer1()
{
  // Disable interrupts
  noInterrupts();
  // Clear registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // 1 Hz (16000000/((15624+1)*1024))
  // OCR1A = 15624;

  // 2 Hz (16000000/((31249+1)*256))
  // OCR1A = 31249;

  // 3 Hz (16000000/((20832+1)*256))
  OCR1A = 20832;

  // 4 Hz (16000000/((15624+1)*256))
  // OCR1A = 15624;

  // 5 Hz (16000000/((3124+1)*1024))
  // OCR1A = 3124;

  // 10 Hz (16000000/((6249+1)*256))
  // OCR1A = 6249;

  // CTC
  TCCR1B |= (1 << WGM12);

  // Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // Output Compare Match A Interrupt Enable
  TIMSK1 |= (1 << OCIE1A);

  // Re-enable interrupts
  interrupts();
}