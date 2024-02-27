// WP 6 Exercise 1 Template DIT 632

#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6
 
int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal

void setup() {
 
  Serial.begin(9600);
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);  
  
  attachInterrupt(digitalPinToInterrupt(interruptPin1), ISR1, CHANGE);

  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); 
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10);
}

void loop() {
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  delay(1000); // TinkerCad...bug
  analogWrite(PWM2, 10);
  
  while(1)
  {
    int directionReady = 0;
    int speedReady = 0;
    
    char directionBuffer[10];
    char speedBuffer[10];
    int direction;
    int speed;
    
    // Ask user for direction
    Serial.print("Please input the direction (-1, 1)\n");
    while(!directionReady)
    {
      directionReady = Serial.readBytes(directionBuffer, 3);
      direction = atoi(directionBuffer);
    }
    
    Serial.print("The direction is: ");
    Serial.println(direction);
    
    // Ask user for speed
    Serial.print("Please input the speed (0-255)\n");
    while(!speedReady)
    {
      speedReady = Serial.readBytes(speedBuffer, 5);
      speed = atoi(speedBuffer);
    }
    
    Serial.print("The speed is: ");
    Serial.println(speed);
    
    // We successfuly read the input
    if (directionReady != 0 && speedReady != 0)
    {
      if (speed > 255)
      {
        speed = 255;
      }
      else if (speed < 0)
      {
        speed = 0;
      }
      
      if (direction == -1)
      {
        analogWrite(PWM1, speed);
        analogWrite(PWM2, 0);
      }
      else
      {
        analogWrite(PWM1, 0);
        analogWrite(PWM2, speed);
      }
    }
  }
}

int getInput(){
  
  int ready = 0;
  char buf[3];
  int input = -1;
  
  Serial.print("Please enter the desired position: \n");
  
  while(!ready){
    ready = Serial.readBytes(buf,3);
    input = atoi(&buf[0]);
  }
 
  return input;
}  
