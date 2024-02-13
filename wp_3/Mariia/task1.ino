// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 1
// Submission code: xxxxxx (provided by your TA-s)

// declare pin variable
int led1 = 12;
int led2 = 8;

// setup initial block
void setup()
{
    // add pin of type output to the scope
    pinMode(led1, OUTPUT);
    // add pin of type output to the scope
    pinMode(led2, OUTPUT);
}

// block of code that will be executed repetetively
void loop()
{
    // set led1 to ON mode
    digitalWrite(led1, HIGH);
    // set led2 to ON mode
    digitalWrite(led2, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    // set pin1 to OFF mode to make it blink every 1 second
    digitalWrite(led1, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
}