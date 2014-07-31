/*
 Shoots lasers in random directions while also displaying color LED's between sequences. Uses a switch
 to go from laser to idle mode, which does a rainbow transition with the LED's.
 By Wilkins Fernandez
 */

#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <MemoryFree.h>
/* This is program is written for the Arduino Leonardo Board. 
 What makes this specific to this board is the usage of attachInterrupt 
 http://arduino.cc/en/Reference/attachInterrupt listening to interrupt 4. 
 Update the TOGGLE_PIN variable if needed. */

// Set PIN's
unsigned const int RING_PIN = 2;
unsigned const int TOGGLE_PIN = 7;
unsigned const int LASER_PIN = 8;
unsigned const int SERVO_BASE_PIN = 9;
unsigned const int SERVO_TOP_PIN = 10;


// Define modules
/****************************************************/
// LED ring
Adafruit_NeoPixel ring = Adafruit_NeoPixel(16, RING_PIN);
// Define servo's
Servo servo_base;
Servo servo_top;

// Start/End position for servo
int position[] = {
  0, 0};

// volatile directs the compiler to load the variable from 
// RAM and not from a storage register ("active memory") 
// where the value can be inaccurate
volatile int toggle_state;


// Game parameters
/****************************************************/
// Top servo's min/max positions for limiting laser pointing area
const unsigned int SERVO_TOP_MAX_POS = 130;
const unsigned int SERVO_TOP_MIN_POS = 55; // Lower number is closer to bot 

// Servo speed, sequence delays, pause delay
const unsigned int MAX_SERVO_SPEED = 55;
const unsigned int MIN_SERVO_SPEED = 75;
const unsigned int MIN_SEQUENCE_DELAY = 10;
const unsigned int MAX_SEQUENCE_DELAY = 50;


void setup() {
  // Set pins
  pinMode(LASER_PIN, OUTPUT);
  pinMode(RING_PIN, OUTPUT);

  // Instantiate modules NeoPixel
  ring.begin();
  ring.show();
  // Instantiate laser
  laserOff();

  // Set the toggle switch using internal pull-up resistors
  // INPUT_PULLUP inverts the behavior, where HIGH means the sensor 
  // is off, and LOW means the sensor is on. 
  pinMode(TOGGLE_PIN, INPUT_PULLUP);

  // When the toggle switch is CHANGEd, call the toggleState function
  attachInterrupt(4, toggleState, CHANGE);

  // The reset button on the board will generate a new random seed
  randomSeed(A0);

  // Intro LED sequence
  colorWipe(ring.Color(255,255,255), 100);

  // Attach servo
  servo_base.attach(SERVO_BASE_PIN);
  servo_top.attach(SERVO_TOP_PIN);

  // Assign toggle_state the initial value of the toggle_pin (toggle switch)
  toggleState();

  Serial.begin(9600);
}

// Updates the toggle_state based on the switch's input reading
void toggleState(){
  toggle_state = digitalRead(TOGGLE_PIN);
}

void loop() {
  // Play game
  if(toggle_state == HIGH){
    // If the servos are detached, it's because toggle_state read LOW at some point
    attachServos();
    // Before each game, wipe the LED's with a new color
    colorWipe(randomColor(), 1);
    // Play a random game!
    play(randomGame());
  } 
  // Idle sequence
  else {
    // Center servos position before detaching (turning "off")
    calibrate();
    // Detach servos to prevent them from jittering
    detachServos();
    // Turn of the laser
    laserOff();
    // Rainbow sequence for LED ring
    rainbow(100);
  }
}

