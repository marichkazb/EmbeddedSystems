// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 2 and 3
// Submission code: 908233 (provided by your TA-s)

// Declare variables for storing Pin values
int RED = 13;    // pin number for red LED
int YELLOW = 12; // pin number for yellow LED
int GREEN = 11;  // pin number for green LED

int TEMP_PIN = A0;
int LIGHT_PIN = A1;

// declare variable to store delay time in seconds
int delaySec = 1;

// main function for setup before execution
void setup()
{
    Serial.begin(9600);      // initialize serial monitor
    pinMode(RED, OUTPUT);    // initialize red pin of type output
    pinMode(YELLOW, OUTPUT); // initialize yellow pin of type output
    pinMode(GREEN, OUTPUT);  // initialize green pin of type output
}

// function that will be executed repetatively
void loop()
{
    // read analog value to int
    int temperature = analogRead(TEMP_PIN);
    // Convert analog reading to voltage
    double voltage = temperature * (5.0 / 1023.0);
    // Calculate temperature using provided formula
    double temp = (voltage - 0.5) * 100;
    // convert analog value of light pin to integer value using formula
    int light = map(analogRead(LIGHT_PIN), 0, 1023, 0, 100);

    // print temperature message
    Serial.print("Temperature: ");
    // print temperature value
    Serial.println(temp);
    // print light message
    Serial.print("Light: ");
    // print light value
    Serial.println(light);
    Serial.print(voltage);

    // start the logic block that corresponds to the dependencies
    // specified in the task description
    if (light == 0)
    { // if light is 0
        if (temp >= -12)
        {
            setRED();
        } // if temp outside range <-12, light red pin
        else
        {
            setGREEN();
        } // othervise correct, light green pin
    }

    else if (light > 1 && light <= 20)
    { // if light in range 1-20%. Temp should be -12-0
        if (temp < -12)
        {
            setYELLOW();
        } // if temp lower then light yellow pin
        else if (temp > 0)
        {
            setRED();
        } // if temp higher than should be, than red pin
        else
        {
            setGREEN();
        } // othervise correct, light green pin
    }

    else if (light > 21 && light <= 60)
    { // if light in range 21-60%. Temp should be 0-20
        if (temp < 0)
        {
            setYELLOW();
        } // if temp lower then light yellow pin
        else if (temp > 20)
        {
            setRED();
        } // if temp higher than it should be then light yellow pin
        else
        {
            setGREEN();
        } // othervise correct, light green pin
    }

    else if (light > 61 && light < 100)
    { // if light in range 61-100%. Temp should be >=21
        if (temp < 21)
        {
            setYELLOW();
        } // if temp lower than should be, then light yellow pin
        else
        {
            setGREEN();
        } // othervise correct, light green pin
    }

    // delay the execution by delaySec converted to milliseconds
    delay(delaySec * 1000);

    digitalWrite(RED, LOW);    // set red pin to OFF
    digitalWrite(GREEN, LOW);  // set green pin to OFF
    digitalWrite(YELLOW, LOW); // set yellow pin to OFF
}

// helper function to set red pin to ON
void setRED()
{
    digitalWrite(RED, HIGH); // set red pin to ON
}

// helper function to set yellow pin to ON
void setYELLOW()
{
    digitalWrite(YELLOW, HIGH); // set yellow pin to ON
}

// helper function to set green pin to ON
void setGREEN()
{
    digitalWrite(GREEN, HIGH); // set green pin to ON
}
