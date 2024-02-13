// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 2
// Submission code: xxxxxx (provided by your TA-s)

// Include section
#include <Keypad.h> // Keypad library

#define WAIT 1000

/**
 * Initialize a 2D array that maps each combination of
 * row and column to a specific character in tke keypad
 */
char mapping[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

const byte ROWS = 4; // Number of rows for the keypad
const byte COLS = 4; // Number of columns for the keypad

byte rowPins[ROWS] = {11, 10, 9, 8}; // Array that stores the pins for the rows
byte colPins[COLS] = {7, 6, 5, 4};   // Array that stores the pins for the columns

/**
 * Variable to keep track of time for a none blocking
 * delay
 */
unsigned long startTime;

/**
 * Variable that allows the program to tell wether it's
 * allowed to press a key or not
 */
uint8_t canPress;

// Create keypad variable based on our attributes using the keypad library
Keypad customKeypad = Keypad(makeKeymap(mapping), rowPins, colPins, ROWS, COLS);

// Setup that initializes the Arduino
void setup()
{
    // Initialize serial communication to 9600 baud rate
    Serial.begin(9600);

    // Initialize startTime to the currentTime in milliseconds
    startTime = millis();

    // Initialize canPress to 1
    // This means that from the beginning any key can be press.
    canPress = 1;
}

// Loop that repeats constantly
void loop()
{
    /**
     * If the currentTime - startTime is bigger than our waiting time.
     *
     * This means that once the defined waiting time has passed
     */
    if (millis() - startTime >= WAIT)
    {
        // Reset startTime to the currentTime
        startTime = millis();
        // Reset canPress to 1. This allows the user to press any key again
        canPress = 1;
    }

    // Get the current key pressed, or none if not key is being pressed
    char cKey = customKeypad.getKey();

    // If there is a key being pressed and it's been more than 1 second since the last press
    if (cKey && canPress == 1)
    {
        // Set canPress to 0 so the user can't press any key until it's reset
        canPress = 0;
        startTime = millis();
        // Print the key
        Serial.println(cKey);
    }
}
