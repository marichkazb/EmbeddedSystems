// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 5
// Exercise 2
// Submission code:  (provided by your TA-s)

// Reference: our own work at wp_4
/**
 * This program makes use of TIMER0, which is an 8 bit timer, and uses a
 * preescaler of 1024. Therefore, the maximum time we can keep track of
 * is approximately 16 ms.
 *
 * 16 MHz / 1024 -> 15625 Hz.
 * 15625 Hz has a period of 0.000064 [s]econds or 64 [us].
 * The maximum number than an 8 bit timer can store is 255. (Timers are 0 index)
 * 64 [us] * (255 + 1) = 16384 [us] -> 16.384 [ms]
 *
 * 16.384 [ms] is the maximum time we can keep track of with an 8 bit timer.
 * Due to this, we have to use an additional counter that increments each
 * time the interrupt is being called, to keep track of the time in seconds.
 *
 * 1 [s] = 1000 [ms] -> 1000 [ms] / 16.384 [ms] = 61.03515625 ~ 61
 *
 * Therefore, every 61 interrupts, approximately 1 second will have passed.
 */

#define STIME 61       // Defines the number of interrupts necessary for 1 second to be registered
#define TEMP_SENSOR A0 // Temperature sensor pin

int counter = 0; // Counter to keep track on how many interrupts we have left before executing our code

/**
 * The threshold at which the counter will execute our code.
 * If time is set up to 1, this is 61, otherwise it would be 61 times
 * the multiplier the user chooses.
 */
int counterLimit;

float temperature;                         // The current temperature being monitored
int displayTemperature = 0;                // "Boolean" that determines wether the temperature should be displayed or not
int temperatureRanges[] = {0, 18, 30, 40}; // The temperature thresholds that the user determines
const int mask = 0b11111000;               // Mask that determines which LEDs should be light up

/**
 * Setter for the timer.
 * This function will update the counterLimit value based on the number of
 * seconds the user inputs.
 *
 * counterLimit will be equal to the number of seconds times 61.
 */
void setTimer(double seconds);

/**
 * Function that sets the temperature thresholds at which certain LEDs
 * will be turned on/off.
 *
 * INPUT:
 *  first: temperatures lower tan this value will light up the Blue LED
 *  second: temperatures between first and second will light up both the Blue LED and the Green LED
 *  third: temperatures between second and third will light up the Blue LED, the Green LED, and the Yellow LED
 *  fourth: temperatures between third and fourth will light up all but the Red LED,
 *          while temperatures bigger than fourth will light up all LEDs
 */
void setTemperatureRanges(int first, int second, int third, int fourth);

// Function to be executed at the beginning  of the program
void setup()
{
    // Set the temperature ranges
    setTemperatureRanges(0, 18, 30, 40);

    // Set the pins 7, 6, 5, 4, and 3 to OUTPUT
    DDRD = 0b11111000;

    // Disable timer interrupts to run critical code uninterrupted
    cli();

    TCCR0A = 0;           // Reset registry to 0
    TCCR0B = 0;           // Reset registry to 0
    TCCR0B |= 0b00000101; // Set a 1024 preescalar to timer 0

    TIMSK0 |= 0b00000010; // Set compare match to OCR0A

    OCR0A = 255; // Set the compare match OCR0A to 255 (max number given by the equation)

    TCNT0 = 0; // Reset counter to 0

    // Initialize a timer of 1 second
    setTimer(1);

    // Enable interrupts again
    sei();
}

// Function to run code repeatedly
void loop()
{
    // Read the voltage in the temperature sensor pin
    double voltage = ((analogRead(TEMP_SENSOR)) * 5.0 / 1023.0) * 1000;

    // Calculate the temperature given by the equation
    temperature = (voltage - 500) / 10.0;

    // If the interrupt has determined that we should display the temperature
    if (displayTemperature == 1)
    {
        // If the temperature is in the first interval
        if (temperature < temperatureRanges[0])
        {

            int shifted = mask << 4; // 11111000 << 4 -> 1111 1000 0000
            // Light up Blue
            PORTD = shifted;
        }
        else if (temperature < temperatureRanges[1])
        {
            int shifted = mask << 3; // 11111000 << 3 -> 0111 1100 0000
            // Light up Blue
            // Light up Green
            PORTD = shifted;
        }
        else if (temperature < temperatureRanges[2])
        {
            int shifted = mask << 2; // 11111000 << 2 -> 0011 1110 0000
            // Light up Blue
            // Light up Green
            // Light up Yellow
            PORTD = shifted;
        }
        else if (temperature < temperatureRanges[3])
        {
            int shifted = mask << 1; // 11111000 << 1 -> 0001 1111 0000
            // Light up Blue
            // Light up Green
            // Light up Yellow
            // Light up Orange
            PORTD = shifted;
        }
        else
        {
            int shifted = mask << 0; // 11111000 << 0 -> 0000 1111 0000
            // Light up Blue
            // Light up Green
            // Light up Yellow
            // Light up Orange
            // Light up Red
            PORTD = shifted;
        }
        displayTemperature = 0;
    }
}

/**
 * Interrupt function for comp vector A of timer 0.
 *
 * This function will be executed every time the interrupt timer is triggered
 */
ISR(TIMER0_COMPA_vect)
{
    // Update the counter
    counter++;
    // Reset the timer counter
    TCNT0 = 0;

    // If the counter is bigger than the counterLimit (i.e. 61 for 1 second)
    if (counter >= counterLimit)
    {
        // Reset the counter
        counter = 0;

        // A respective amount of seconds has passed, therefore, we display the temperature
        displayTemperature = 1;
    }
}

void setTimer(double seconds)
{
    // Set counterLimit to 61 times the number of second the user inputs
    counterLimit = seconds * STIME;
}

void setTemperatureRanges(int first, int second, int third, int fourth)
{
    temperatureRanges[0] = first;  // Assign first to the 0 index of the temperatureRanges array
    temperatureRanges[1] = second; // Assign second to the 0 index of the temperatureRanges array
    temperatureRanges[2] = third;  // Assign third to the 0 index of the temperatureRanges array
    temperatureRanges[3] = fourth; // Assign fourth to the 0 index of the temperatureRanges array
}
