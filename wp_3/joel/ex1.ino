// Declare and assign pin numbers
const int blinkerLed = 13;
const int buttonLed = 12;
const int buttonPin = 2;

// Non-blocking timer variables
int currentMs;
int prevMs = 0;
int interval = 1000; // One second delay

// Button and led state
int ledState = LOW;
int buttonState = LOW;

// Setup function
void setup()
{
    // Assign pins and set mode
    pinMode(blinkerLed, OUTPUT); // Blinker LED set to output mode
    pinMode(buttonLed, OUTPUT);  // Button LED set to output mode
    pinMode(buttonPin, INPUT);   // Button set to input mode
}

// Main loop
void loop()
{
    // Set current millis to now
    currentMs = millis();

    // Non-blocking delay loop
    while (currentMs - prevMs >= interval) // If time since last change has surpassed interval
    {
        // Last changed becomes now
        prevMs = currentMs;
        // Read current state of the led
        ledState = digitalRead(blinkerLed);
        // Set led to the opposite of what it is now
        digitalWrite(blinkerLed, !ledState);
    }
    // Read state of button
    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH) // If button is pressed
    {
        // Turn led on
        digitalWrite(buttonLed, HIGH);
    }
    else // If button is depressed
    {
        // Turn led off
        digitalWrite(buttonLed, LOW);
    }
}