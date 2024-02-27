// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 6
// Exercise 1.1
// Submission code: 073648 (provided by your TA-s)

// Includes section
#include <Keypad.h>            // Keypad library
#include <Adafruit_NeoPixel.h> // NeoPixel library

// Defines section
#define SG_PIN 2        // Pin connected to the NeoPixel ring
#define NUM_LEDS 12     // Number of NeoPixels in the ring
#define INPUT_LENGTH 7  // Lenght of code input
#define NUM_ADDRESSES 8 // Number of addresses

// Constants for keypad
const byte numRows = 4; // number of rows on the keypad
const byte numCols = 3; // number of columns on the keypad

// Keymap that defines the key values for the buttons
char keymap[numRows][numCols] = {
    {'1', '2', '3'}, // First row
    {'4', '5', '6'}, // Second row
    {'7', '8', '9'}, // Third row
    {'*', '0', '#'}  // Fourth row
};

// Counter for input numbers
int counter = 0;

// Char array for saving the keypad input
char sequence[INPUT_LENGTH];

// List of valid addresses
char address[NUM_ADDRESSES][INPUT_LENGTH] = {
    {'1', '2', '3', '4', '5', '6', '7'}, // Address 1
    {'3', '4', '2', '8', '2', '4', '8'}, // Address 2
    {'6', '5', '1', '7', '3', '2', '7'}, // Address 3
    {'5', '2', '7', '6', '4', '1', '4'}, // Address 4
    {'4', '1', '3', '5', '5', '3', '8'}, // Address 5
    {'3', '4', '2', '4', '6', '4', '4'}, // Address 6
    {'2', '3', '8', '3', '3', '2', '8'}, // Address 7
    {'9', '9', '9', '9', '9', '9', '9'}  // Address 8
};

// Mapping of index to chevron layout
int chevron[7] = {3, 4, 5, 9, 10, 11, 1};

// Current character pressed on keypad
char keypressed;

// Initilaization of NeoPixel ring with 12 LEDs
Adafruit_NeoPixel stargate(NUM_LEDS, SG_PIN, NEO_GRB + NEO_KHZ800);

// Color array with mapped indicies to mimic fading RGB scale
uint32_t colors[NUM_LEDS] = {
    stargate.Color(255, 191, 0), // Brightest
    stargate.Color(213, 149, 0), // Brighter
    stargate.Color(170, 117, 0), // Moderate
    stargate.Color(85, 41, 0),   // Medium
    stargate.Color(42, 21, 0),   // Low
    stargate.Color(20, 10, 0),   // Lowest
    stargate.Color(0, 0, 0),     // Turned off
    stargate.Color(0, 0, 0),     // Turned off
    stargate.Color(0, 0, 0),     // Turned off
    stargate.Color(0, 0, 0),     // Turned off
    stargate.Color(0, 0, 0),     // Turned off
    stargate.Color(0, 0, 0)      // Turned off
};

// Function prototypes
int validateAddress();                          // Function that iterates through addresses and validates/invalidates input
void pulse(int index);                          // Function that makes ring at index rotate and pulse
void setAll(int r, int g, int b);               // Set all LEDs in the NeoPixel ring to a specific color
void blink(int index, int times, int interval); // Set a specific LED to blink a specified amount of times at a specifed interval
void blinkAll(int times, int interval);         // Blink all lights in the NeoPixel ring a specified amount of times at a specifed interval
void dialSequence();                            // Function that initiates dial sequence

// Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9, 8, 7, 6}; // Rows 1 to 4
byte colPins[numCols] = {5, 4, 3};    // Columns 1 to 3

// initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

// Setup function
void setup()
{
    Serial.begin(9600);         // Initialize serial monitor to 9600 baud
    stargate.begin();           // Initialize the NeoPixel ring
    stargate.setBrightness(75); // Set brightness
    stargate.show();            // Display changes to stargate
}

// Loop function
void loop()
{

    // While there are still numbers left to input in address
    while (counter < INPUT_LENGTH)
    {

        // If key is pressed, this key is stored in 'keypressed' variable
        keypressed = myKeypad.getKey();

        // If key is not equal to 'NO_KEY', then this key is printed out
        if (keypressed != NO_KEY)
        {
            Serial.print("Button pressed: "); // CLI print for better ux
            Serial.println(keypressed);       // Print value of key pressed
            sequence[counter] = keypressed;   // Store character in sequence
            int indx = (int)keypressed - '0'; // Cast key character to int
            blink(indx, 3, 200);              // Blink associated LED for visual confirmation
            stargate.show();                  // Display changes to stargate
            counter++;                        // Increment counter
        }
    }

    // After all key inputs are read, initiate dial sequence
    dialSequence();

    // Blink all lights
    blinkAll(5, 250);

    // Call validation function and store result in variable
    int valid = validateAddress();

    // If code address entered is valid
    if (valid == 1)
    {
        // Set all lights to blue for successful dial
        setAll(0, 0, 255);
    }
    // If code address entered is invalid
    else
    {
        // Set all lights to red for unsuccessful dial
        setAll(255, 0, 0);
    }

    // Keep lights displayed for 1 second
    delay(1000);

    // Turn off all lights
    setAll(0, 0, 0);

    // Reset counter for new address attempt
    counter = 0;
}

// Validation function
int validateAddress()
{
    // Initialize valid
    int valid;
    // For every address in the address array
    for (int i = 0; i < NUM_ADDRESSES; i++)
    {
        // Assume address is valid
        valid = 1;

        // For every number in the sequence
        for (int j = 0; j < INPUT_LENGTH; j++)
        {
            // If character in sequence does not match character at same position in current address
            if (address[i][j] != sequence[j])
            {
                // Set valid to 0
                valid = 0;
                // Break out of the current address loop
                break;
            }
        }
        // If address did not trigger different character block, address is valid
        if (valid == 1)
        {
            // Return 1 for valid address;
            return valid;
        }
    }
    // Return valid
    return valid;
}

// Function that makes LEDs train 360 degrees
void pulse(int index)
{
    // Initialize currentColor variable
    int currentColor;
    // For every LED starting at index
    for (int i = index; i < (NUM_LEDS + index); i++)
    {
        // Current color index set to 0
        currentColor = 0;
        // For every LED counting down from index
        for (int j = i; currentColor < NUM_LEDS; j--)
        {
            // Set previous LED with color index j
            stargate.setPixelColor(j % NUM_LEDS, colors[currentColor]);
            // Increment color index
            currentColor++;
        }
        // Display changes to stargate
        stargate.show();
        // Small delay to visualize rotating LEDs
        delay(100);
    }
    // Blink index LED after one full revolution to "lock in chevron"
    blink(index, 3, 300);
}

// Function to set all LEDs to the same LED value
void setAll(int r, int g, int b)
{
    // For every LED
    for (int i = 0; i < NUM_LEDS; i++)
    {
        // Set color of LED at i to specified RGB value
        stargate.setPixelColor(i, r, g, b);
    }
    // Display changes to stargate
    stargate.show();
}

// Function to blink a specific LED at index a specified amount of times at specified interval
void blink(int index, int times, int interval)
{
    // For all LEDs
    for (int i = 0; i < times; i++)
    {
        stargate.setPixelColor(index, colors[0]); // Set color of LED at index i
        stargate.show();                          // Display changes to stargate
        delay(interval);                          // Interval to display "blinking behaviour"
        stargate.setPixelColor(index, 0, 0, 0);   // Turn off LED at index i
        stargate.show();                          // Display changes to stargate
        delay(interval);                          // Interval to display "blinking behaviour"
    }
}

// Function to blink all LEDs a specified amount of times at specified interval
void blinkAll(int times, int interval)
{
    // For all LEDs
    for (int i = 0; i < times; i++)
    {
        setAll(255, 191, 0); // Set all LEDs to specified RGB value
        delay(interval);     // Interval to display "blinking behaviour"
        setAll(0, 0, 0);     // Turn off all LEDs
        stargate.show();     // Display changes to stargate
        delay(interval);     // Interval to display "blinking behaviour"
    }
}

// Function that initiates visual dial sequence
void dialSequence()
{
    // For all chevrons
    for (int i = 0; i < 7; i++)
    {
        pulse(chevron[i]); // Pulse chevron at index i
        setAll(0, 0, 0);   // Turn off all LEDs
    }
}