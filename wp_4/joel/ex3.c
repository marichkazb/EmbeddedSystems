// (C) Joel Celén, group: 8__ (2024)
// Work package 4
// Exercise 3
// Submission code:  (provided by your TA-s)

// ---- Source code for interrupt timer ----

// AVR Timer CTC Interrupts Calculator
// v. 8
// http://www.arduinoslovakia.eu/application/timer-calculator
// Microcontroller: ATmega328P
// Created: 2024-02-18T11:17:54.307Z

// ------------------------------------------

// Include section
#include <Adafruit_NeoPixel.h>

// Function prototypes
void setupTimer1();     // Function to set up timed interrupts
ISR(TIMER1_COMPA_vect); // Interrupt function
float convertCelsius(); // Function that converts analog value to celsius
void setRing();         // Function that sets all the LEDs in the NeoPixel ring
void setLeds();         // Function that sets boundary LEDs

// Define section
#define TEMP_SENSOR A0
#define PIXEL_RING 6   // Pin connected to the NeoPixel ring
#define NUM_LEDS 12    // Number of NeoPixels in the ring
#define BRIGHTNESS 100 // NeoPixel brightness (0-255)
#define MAX_LED 13     // Pin for max value LED
#define MIN_LED 10     // Pin for min value LED

// Global varibles
volatile int tempValue = 0;                                            // Variable for analog reading from temp sensor
volatile int newReading = 0;                                           // Flag for when a new reading is available
Adafruit_NeoPixel ledRing(NUM_LEDS, PIXEL_RING, NEO_GRB + NEO_KHZ800); // NeoPixel ring declaration
float min_range = -30.0;                                               // Minimum value of temp range
float max_range = 80.0;                                                // Maximum value of temp range

// 2D array that holds the RGB values matching each LED
int colorScale[NUM_LEDS][3] = {
    {0, 255, 0},   // Green
    {85, 255, 0},  // Light green
    {170, 255, 0}, // Light yellow-green
    {255, 255, 0}, // Yellow-green
    {255, 170, 0}, // Yellow
    {255, 85, 0},  // Orange-yellow
    {255, 0, 0},   // Orange
    {255, 0, 85},  // Orange-red
    {255, 0, 170}, // Red-orange
    {255, 0, 255}, // Red
    {170, 0, 255}, // Deep red
    {85, 0, 255}   // Dark red
};

// Arduino setup function
void setup()
{
  setupTimer1();                     // Call the function to set up Timer2
  Serial.begin(9600);                // Start serial
  ledRing.begin();                   // Initialize the NeoPixel ring
  ledRing.setBrightness(BRIGHTNESS); // Set brightness
  ledRing.show();                    // Initialize initial LED values
  pinMode(MAX_LED, OUTPUT);          // Assign pinMode to max led
  pinMode(MIN_LED, OUTPUT);          // Assign pinMode to min led
}

// Loop function
void loop()
{
  // If there is a new reading
  if (newReading == 1)
  {
    // Set the LEDs in the NeoPixel
    setRing();
    // Set threshold LEDs
    setLeds();
    // Set flag to false
    newReading = 0;
  }
}

// Interrupt function skeleton:
// https://www.arduinoslovakia.eu/application/timer-calculator
// Code defined within the function is out original work.
ISR(TIMER1_COMPA_vect)
{
  // Read the value from the temp sensor
  tempValue = analogRead(TEMP_SENSOR);
  // Set flag for new reading to true
  newReading = 1;
}

// Function to set the LEDs in the NeoPixel ring according to the temp values
void setRing()
{
  // Convert analog value to celsius and store in a variable
  float celsius = convertCelsius();

  // Set threshold to min_range
  float threshold = min_range;

  // Turn on NeoPixel LEDs based on different values for each LED
  for (int i = 0; i < NUM_LEDS; i++)
  {
    // If current temperature reading is higher than threshold
    if (celsius > threshold)
    {
      // Light up LED at i with the corresponding RBG value at i
      ledRing.setPixelColor(i, colorScale[i][0], colorScale[i][1], colorScale[i][2]);
    }
    // If current temperature reading is below threshold
    else
    {
      // Turn of LED at i
      ledRing.setPixelColor(i, 0, 0, 0); // Turn off pixel
    }
    // Display changes in LEDs
    ledRing.show();
    // Increment threshold by 10c for LED at i+1
    threshold += 10.0;
  }
}

// Function that sets threshold LEDs based on current temp reading
void setLeds()
{
  // Convert analog value to celsius and store in a variable
  float celsius = convertCelsius();

  digitalWrite(MIN_LED, LOW); // Turn off min threshold LED
  digitalWrite(MAX_LED, LOW); // Turn off max threshold LED

  // If current temperature is below min threshold value
  if (celsius < min_range)
  {
    // Light up the min value led
    digitalWrite(MIN_LED, HIGH);
  }
  // If current temperature is above max threshold value
  else if (celsius > max_range)
  {
    // Light up the max value led
    digitalWrite(MAX_LED, HIGH);
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
  noInterrupts();
  // Clear registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // 1 Hz (16000000/((15624+1)*1024))
  OCR1A = 15624;

  // 2 Hz (16000000/((31249+1)*256))
  // OCR1A = 31249;

  // 3 Hz (16000000/((20832+1)*256))
  // OCR1A = 20832;

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