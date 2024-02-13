// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 3
// Submission code: xxxxxx (provided by your TA-s)

// declare variable for temperature pin
int T_PIN = A0;

// main function for setup before execution
void setup()
{
    // initialize pin for temperature of type output
    pinMode(T_PIN, INPUT);
    // initialize serial monitor for printing values
    Serial.begin(9600);
}

void loop()
{
    // read alalog value to int
    int temp = analogRead(T_PIN);
    // Convert analog reading to voltage
    double voltage = temp * (5.0 / 1023.0);
    // Calculate temperature using provided formula
    double temperature = (voltage - 0.5) * 100;
    // print temperature message to the serial monitor
    Serial.print("Temperature ");
    // print temperature value to serial monitor
    Serial.println(temperature);
    // add delay of 0.5 seconds
    delay(500);
}
