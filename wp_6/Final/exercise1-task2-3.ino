// (C) __Mariia Zabolotnia, Joel Celén, Ionel Pop, group: 8__ (2024)
// Work package 6
// Exercise 1.2 and 1.3
// Submission code: 073648 (provided by your TA-s)

#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6

int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 3;    // Proportional constant for controller (tuning parameter)
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

  // create attachInterrupt for pin ENCA that will trigger function ISR_readEncoder every time signal on Rising value
  attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);

  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10);
  // add delay in milliseconds
  delay(1000); // TinkerCad bug
  // initialize motor movement
  analogWrite(PWM1, 10);
  // print user message
  Serial.println("Motors initialized");
}

// function of the code that will be repetitively executed
void loop()
{
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  // write PWM2 as 10
  analogWrite(PWM2, 10);

  // print user message
  Serial.println("Motors stopped before reading input");

  // Check if motor rotated all the way around, and reset counter
  if (pos > 2299)
  {
    deg = deg - 359;
    pos = pos - 2299;
  }
  if (pos < 0)
  {
    deg = 359 + deg;
    pos = 2299 + pos;
  }

  deg = map(pos, 0, 2299, 0, 359);

  // Print current position
  Serial.print("The current position is: ");
  Serial.print(deg);
  Serial.print("\n");

  // Get input
  degtarget = getInput();

  Serial.print("Degree target is: ");
  Serial.print(degtarget);
  Serial.print("\n");

  // Calculate initial error
  e = degtarget - deg;
  Serial.print("The initial error is: ");
  Serial.print(e);
  Serial.print("\n");

  while (e > 5 || e < -5)
  {
    if (pos > 2299)
    {
      deg = deg - 359;
      pos = pos - 2299;
    }
    if (pos < 0)
    {
      deg = 359 + deg;
      pos = 2299 + pos;
    }
    deg = map(pos, 0, 2299, 0, 359);

    Serial.print("Current position: ");
    Serial.print(pos);
    Serial.print("\tCurrent degrees: ");
    Serial.print(deg);

    e = degtarget - deg;

    Serial.print("\tError: ");
    Serial.print(e);
    Serial.println("");

    speed = getAction(e);

    Serial.print("\tSpeed: ");
    Serial.print(speed);
    Serial.println("");

    // Send speed signal to motor
    // Rotating clockwise
    if (speed >= 0)
    {
      if (speed < 100)
      {
        // motor does not react with too low inputs
        speed = 100;
      }
      analogWrite(PWM2, speed);
      analogWrite(PWM1, 10);
    }
    // Rotating counter-clockwise
    else
    {
      if (-speed < 100)
      {
        // motor does not react with too low inputs
        speed = -100;
      }
      analogWrite(PWM1, -speed);
      analogWrite(PWM2, 10);
    }

    // Calculate new error
    e = degtarget - deg;
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

// function to get the
int getAction(int error)
{

  // calculate out value as kp *error value
  u_out = kp * error;

  // u_out cannot be more than 255...
  if (u_out > 254)
  {
    // then we return 255
    return 255;
  }
  //...or less than -254
  else if (u_out < -254)
  {
    // then we return -255
    return -255;
  }
  else
    // otherwise return default value of u_out
    return u_out;
}

// function that is executed on interrupts
void ISR_readEncoder()
{
  // read the pin ENCB and store value to b
  int b = digitalRead(ENCB);

  // if the value is positive
  if (b > 0)
  {
    // increase the position
    pos++;
  }
  // otherwise if it's negative
  else
  {
    // decrease the position
    pos--;
  }
}
