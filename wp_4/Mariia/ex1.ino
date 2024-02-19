// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 4
// Exercise 1
// Submission code:  (provided by your TA-s)

// AVR Timer CTC Interrupts Calculator
// v. 8
// http://www.arduinoslovakia.eu/application/timer-calculator
// Microcontroller: ATmega328P
// Created: 2024-02-19T16:05:14.133Z

// assign led pin values
int led1 = 13; // led1 is connected to pin 13
int led2 = 12; // led2 is connected to pin 12
int led3 = 11; // led3 is connected to pin 11
int led4 = 10; // led4 is connected to pin 10
int led5 = 9;  // led5 is connected to pin 9

// pin A0 is connected to the temperature sensor
int TEMP_PIN = A0;

// function to be executed at the beginning of the program
void setup()
{
    pinMode(led1, OUTPUT);    // configure led1 as an OUTPUT pin
    pinMode(led2, OUTPUT);    // configure led1 as an OUTPUT pin
    pinMode(led3, OUTPUT);    // configure led1 as an OUTPUT pin
    pinMode(led4, OUTPUT);    // configure led1 as an OUTPUT pin
    pinMode(led5, OUTPUT);    // configure led1 as an OUTPUT pin
    pinMode(TEMP_PIN, INPUT); // configure led1 as an OUTPUT pin
    setupTimer1();            // initialize setip timer function
    Serial.begin(9600);       // initialize serial communication
}

// loop function empty since main functionality is in ISR
void loop()
{
}

// setupTimer2 function, source code from:
// http://www.arduinoslovakia.eu/application/timer-calculator
// code defined in the function scope is our original work
ISR(TIMER1_COMPA_vect)
{
    digitalWrite(led1, LOW); // set led1 to LOW, meaning off
    digitalWrite(led2, LOW); // set led2 to LOW, meaning off
    digitalWrite(led3, LOW); // set led3 to LOW, meaning off
    digitalWrite(led4, LOW); // set led4 to LOW, meaning off
    digitalWrite(led5, LOW); // set led5 to LOW, meaning off

    // process temperature input
    // read info from temp_pin
    int temperature = analogRead(TEMP_PIN);
    // convert to the voltage according to the formula
    double voltage = temperature * (5.0 / 1023.0);
    // get the temperature value based on voltage
    double temp = (voltage - 0.5) * 100;
    // print temperature
    Serial.println(temp);

    // assign the LEDs certain ranges and light up them is the temperature is in the led range
    // for led 1 range is -41 to -20
    if (temp > -41 && temp < -20)
    {
        digitalWrite(led1, HIGH);
    }
    // for led 2 range is -20 to 0
    if (temp > -20 && temp < 0)
    {
        digitalWrite(led2, HIGH);
    }
    // for led 3 range is 0 to 20
    if (temp > 0 && temp < 20)
    {
        digitalWrite(led3, HIGH);
    }
    // for led 4 range is 40 to 80
    if (temp > 40 && temp < 80)
    {
        digitalWrite(led4, HIGH);
    }
    // for led 5 range is 80 to 125
    if (temp > 80 && temp <= 125)
    {
        digitalWrite(led5, HIGH);
    }
}

// setupTimer1 function, source code from:
// http://www.arduinoslovakia.eu/application/timer-calculator
void setupTimer1()
{
    // start the function
    noInterrupts();
    // Clear registers
    TCCR1A = 0; // Clear register
    TCCR1B = 0; // Clear register
    TCNT1 = 0;  // Clear register

    // 1 Hz (16000000/((15624+1)*1024))
    OCR1A = 15624;
    // CTC
    TCCR1B |= (1 << WGM12);
    // Prescaler 1024
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // Output Compare Match A Interrupt Enable
    TIMSK1 |= (1 << OCIE1A);
    // call the main function interrupts
    interrupts();
}
