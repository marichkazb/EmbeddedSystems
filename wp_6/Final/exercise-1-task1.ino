// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 6
// Exercise 1.1
// Submission code: 073648 (provided by your TA-s)

#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6

int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5;    // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal

// function to initialize initial data and pins
void setup()
{
  Serial.begin(9600);          // start serial monitor t obe able to print information
  pinMode(ENCA, INPUT_PULLUP); // initialize ENCA pin of type INPUT_PULLUP
  pinMode(ENCB, INPUT_PULLUP); // initialize ENCB pin of type INPUT_PULLUP
  pinMode(PWM1, OUTPUT);       // initialize PWM1 pin of type OUTPUT
  pinMode(PWM2, OUTPUT);       // initialize PWM2 pin of type OUTPUT

  // create attachInterrupt for pin interruptPin1 that will trigger function ISR1 every time signal on the pin changes
  attachInterrupt(digitalPinToInterrupt(interruptPin1), ISR1, CHANGE);

  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10);
  // add delay in milliseconds
  delay(1000); // TinkerCad bug
  // initialize motor movement
  analogWrite(PWM1, 10);
}

// function of the code that will be repetitively executed
void loop()
{
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  // add delay in milliseconds
  delay(1000); // TinkerCad...bug
  // write PWM2 as 10
  analogWrite(PWM2, 10);

  // infinite loop
  while (1)
  {
    // initialize helper "bool" variable to verify that direction is ready for processing
    int directionReady = 0;
    // initialize helper "bool" variable to verify that speed is ready for processing
    int speedReady = 0;

    // initialize the direction buffer for scanning the numbers
    char directionBuffer[10];
    // initialize the speed buffer for scanning the input
    char speedBuffer[10];
    // declare helper variable for storing direction value
    int direction;
    // declare helper variable for storing speed value
    int speed;

    // Ask user for direction
    Serial.print("Please input the direction (-1, 1)\n");
    // repeat until the direction is read properly
    while (!directionReady)
    {
      // read from buffer and store to directionReady
      directionReady = Serial.readBytes(directionBuffer, 3);
      // convert the number we got to integer
      direction = atoi(directionBuffer);
    }

    // print user message
    Serial.print("The direction is: ");
    // print value of direction
    Serial.println(direction);

    // Ask user for speed
    Serial.print("Please input the speed (0-255)\n");
    // repeat until the speed is read properly
    while (!speedReady)
    {
      // read from buffer and store to speedReady
      speedReady = Serial.readBytes(speedBuffer, 5);
      // convert the number we got to integer
      speed = atoi(speedBuffer);
    }
    // print user message
    Serial.print("The speed is: ");
    // print value of speed
    Serial.println(speed);

    // We successfuly read the input
    if (directionReady != 0 && speedReady != 0)
    {
      // handle edge cases - if speed is more than 255, then fallback to 255
      if (speed > 255)
      {
        // assign it back to 255
        speed = 255;
      }
      // if speed is negative
      else if (speed < 0)
      {
        // assign it to 0
        speed = 0;
      }

      // if direction that user provided was -1
      if (direction == -1)
      {
        // start the motor PWM1 with the speed
        analogWrite(PWM1, speed);
        // and PWM2 with 0
        analogWrite(PWM2, 0);
      }
      else
      {
        // and PWM1 with 0
        analogWrite(PWM1, 0);
        // start the motor PWM2 with the speed
        analogWrite(PWM2, speed);
      }
    }
  }
}

// function to get user input
int getInput()
{
  // initialise flag to determine if it's ready
  int ready = 0;
  // create buffer array with value 3
  char buf[3];
  // initialize input to -1
  int input = -1;

  // print user message
  Serial.print("Please enter the desired position: \n");

  // repeat the body until input is valid
  while (!ready)
  {
    // save input from buffer to ready
    ready = Serial.readBytes(buf, 3);
    // convert buffer values to int input
    input = atoi(&buf[0]);
  }

  // return input value
  return input;
}
