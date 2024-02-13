// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 1
// Submission code: 908233 (provided by your TA-s)

// declare pin variable
int led1 = 12;  // Set pin 12 as the output pin for LED 1
int led2 = 8;   // Set pin 8 as the output pin for LED 2
int btnPin = 2; // Set pin 2 as the input pin for the Button
int state;      // Variable keep track of the state of the Button

// setup initial block
void setup()
{
    // add pin of type output to the scope
    pinMode(led1, OUTPUT);
    // add pin of type output to the scope
    pinMode(led2, OUTPUT);
    // add pin of type output to the scope
    pinMode(btnPin, INPUT);
    // initialize pin2 as an interrupt that triggers the function controlLED when the state changes
    attachInterrupt(digitalPinToInterrupt(btnPin), controlLED, CHANGE);
    // initialize state to low
    state = LOW;
}

// block of code that will be executed repetetively
void loop()
{
    // set led1 to ON mode
    digitalWrite(led1, HIGH);
    // Wait for 1000 millisecond(s)
    delay(1000);
    // set pin1 to OFF mode to make it blink every 1 second
    digitalWrite(led1, LOW);
    // Wait for 1000 millisecond(s)
    delay(1000);
}

// interrupt function
void controlLED()
{
    // in case the state was LOW, assign it to HIGH
    if (state == 0)
    {
        state = 1;
    }
    // if the state was HIGH assign it to LOW
    else
    {
        state = 0;
    }
    // write the led2 value as the value of the state
    digitalWrite(led2, state);
}