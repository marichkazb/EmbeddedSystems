// WP 6 Exercise 1 Template DIT 632
#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6

int pos = 0;  // Position in ticks
int deg = 0;  // Position in degrees

int degtarget = 0;  // Target position in degrees

int speed = 0;  // Desired motor speed

int kp = 3;     // Proportional constant for controller (tuning parameter)
int u_out = 0;  // output of controller

int e = 0;  // error
int a = 0;  // a-encoder signal
int b = 0;  // b-encoder signal

void setup() {
  Serial.begin(9600);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);

  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10);
  delay(1000);  // TinkerCad bug
  analogWrite(PWM1, 10);

  Serial.println("Motors initialized");
}

void loop() {
  // Stop the motor, but not to zero because then TinkerCad dies....
  //analogWrite(PWM1, 10);
  //delay(1000);  // TinkerCad...bug
  //analogWrite(PWM2, 10);
  analogWrite(PWM1, 10);
  //delay(1000);  // TinkerCad...bug
  analogWrite(PWM2, 10);

  Serial.println("Motors stopped before reading input");

  // Check if motor rotated all the way around, and reset counter
  if (pos > 2299) {
    deg = deg - 359;
    pos = pos - 2299;
  }
  if (pos < 0) {
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

  while (e > 5 || e < -5) {
    if (pos > 2299) {
      deg = deg - 359;
      pos = pos - 2299;
    }
    if (pos < 0) {
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
    if (speed >= 0) {
      if (speed < 100) {
        // motor does not react with too low inputs
        speed = 100;
      }
      analogWrite(PWM2, speed);
      analogWrite(PWM1, 10);
    }
    // Rotating counter-clockwise
    else {
      if (-speed < 100) {
        // motor does not react with too low inputs
        speed = -100;
      }
      analogWrite(PWM1, -speed);
      analogWrite(PWM2, 10);
    }

    // Calculate new error
    e = degtarget - deg;

    // analogWrite(PWM1, 10);
    // analogWrite(PWM2, 200);
  }

  //Serial.println("Outside error");
  // Stop the motor, but not to zero because then TinkerCad dies....
  //analogWrite(PWM1, 10);
  //delay(1000);  // TinkerCad...bug
  //analogWrite(PWM2, 10);

  // // Calculate initial error
  // e = degtarget - deg;

  // Serial.print("Error is: ");
  // Serial.print(e);
  // Serial.print("\n");

  // // Loop until error is zero
  // while (e)
  // {

  //     // Map current position into degrees
  //     deg = map(pos, 0, 2299, 0, 359);

  //     // Get necessary speed signal
  //     speed = getAction(e);

  //     // Send speed signal to motor
  //     // Rotating clockwise
  //     if (speed >= 0)
  //     {
  //         if (speed < 100) // motor does not react with too low inputs
  //             speed = 100;
  //         analogWrite(PWM2, 0);
  //         analogWrite(PWM1, speed);
  //     }

  //     // Rotating counter-clockwise
  //     else
  //     {
  //         if (-speed < 100) // motor does not react with too low inputs
  //             speed = -100;
  //         analogWrite(PWM1, 0);
  //         analogWrite(PWM2, -speed);
  //     }

  //     // Calculate new error
  //     e = degtarget - deg;
  // }
}

int getInput() {

  int ready = 0;
  char buf[3];
  int input = -1;

  Serial.print("Please enter the desired position: \n");

  while (!ready) {
    ready = Serial.readBytes(buf, 3);
    input = atoi(&buf[0]);
  }

  return input;
}

int getAction(int error) {

  u_out = kp * error;

  if (u_out > 254) {  // u_out cannot be more than 255...
    return 255;
  } else if (u_out < -254) {  //...or less than -254
    return -255;
  } else
    return u_out;
}

void ISR_readEncoder() {
  int b = digitalRead(ENCB);

  if (b > 0) {
    pos++;
  } else {
    pos--;
  }
}
