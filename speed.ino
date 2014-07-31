// Generate a random speed and delays
unsigned int randomSpeed(){
  return random(MAX_SERVO_SPEED, MIN_SERVO_SPEED);
}

unsigned int randomDelay(){
  return random(MIN_SEQUENCE_DELAY, MAX_SEQUENCE_DELAY);
}


