// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 3
// Exercise 3
// Submission code: 908233 (provided by your TA-s)

#define WAIT 1000

/**
 * Initialize a 2D array that maps each combination of
 * row and column to a specific character in tke keypad 
*/
const char mapping[4][4] = {
    {'*', '0', '#', 'D'},
    {'7', '8', '9', 'C'},
    {'4', '5', '6', 'B'},
    {'1', '2', '3', 'A'}};

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

// Function prototype declarations
/**
 * Function that checks the current state of the keys and if
 * any key is pressed, it prints it's corresponding character
 * int the serial monitor.
 * 
 * INPUT:
 *  canPress: A pointer to a flag that determines wether
 *              a key can be pressed or not
 *  startTime: A pointer to a variable that keeps track of
 *              the last time a key was pressed. It is reset
 *              to 0 after a key is pressed in this function.
 * 
 * OUTPUT:
 *  None
*/
void checkKeys(uint8_t *canPress, unsigned long *startTime);

/**
 * Helper function that presses a key and prints its value in the
 * serial monitor.
 * 
 * INPUT:
 *  row: The row of the character
 *  col: The column of the character
 *  canPress: A pointer to a flag that determines wether
 *              a key can be pressed or not
 *  startTime: A pointer to a variable that keeps track of
 *              the last time a key was pressed. It is reset
 *              to 0 after a key is pressed in this function.
 * 
 * OUTPUT:
 *  None
*/
void pressKey(int row, int col, uint8_t *canPress, unsigned long *startTime);

// Setup that initializes the Arduino
void setup()
{
    /**
     * Set the registries in PORTB to 0b00001111.
     * This means that pins 13 and 12 will be set up as INPUT,
     * while pins 11 to 8 will be set up as OUTPUT.
     * 
     * PORTB: X X 13 12 11 10 9 8
    */
    DDRB |= 0b00001111; // Set up the rows to OUTPUT
    // D: 7 6 5 4 3 2 1 0

    /**
     * Set the registries in PORTD to 0b00000000.
     * This means that pins while pins 7 to 0 will
     * be set up as INPUT.
     * 
     * PORTD: 7 6 5 4 3 2 1 0
    */
    DDRD |= 0b00000000; // Set up the cols to INPUT

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

    /**
     * If a key can be press
    */
    if (canPress == 1)
    {
        // Check if any key is being pressed using this function
        checkKeys(&canPress, &startTime);
    }
}

void checkKeys(uint8_t *canPress, unsigned long *startTime)
{
    // Iterate through each row
    for (int i = 0; i < 4; i++)
    {
        /**
         * Write 0 to every row but the row that we are currently checking.
         * 
         * For example, if we check row 4 (PIN 8), we set up PORTB to ~(1 << 0)
         * -> PORTB = 0b11111110,
        */
        PORTB = ~(1 << i);

        /**
         * For this part, we check the state of each PIN in PORTD
         * 
         * So for example, to check PIN 7, we do PIND>>7 -> X000 0000 >> 7 = 0000 000X
         * 
         * Then we check the status using a mask 1 -> 0000 000X & 1 = X
        */
        if (((PIND >> 7) & 1) == 0)
        {
            // If pin 7 is active, press the key in col 0
            pressKey(i, 0, canPress, startTime);
            // Debounce delay
            delay(10);
        }
        else if (((PIND >> 6) & 1) == 0)
        {
            // Else If pin 6 is active, press the key in col 1
            pressKey(i, 1, canPress, startTime);
            delay(10);
        }
        else if (((PIND >> 5) & 1) == 0)
        {
            // Else If pin 5 is active, press the key in col 2
            pressKey(i, 2, canPress, startTime);
            delay(10);
        }
        else if (((PIND >> 4) & 1) == 0)
        {
            // Else If pin 4 is active, press the key in col 3
            pressKey(i, 3, canPress, startTime);
            delay(10);
        }
    }
}

void pressKey(int row, int col, uint8_t *canPress, unsigned long *startTime)
{
    // Print the key
    Serial.println(mapping[row][col]);
    // Set the canPress value to 0 so the user can't press any key
    *canPress = 0;
    // Set startTime to current time to avoid the user clicking an input for 1 second
    *startTime = millis();
}
