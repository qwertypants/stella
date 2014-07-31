// Generate random sequence to play
unsigned int randomGame(){
  const unsigned int games = 3; 
  return random(0, games);
}

void play(int sequence){
  unsigned int speed = randomSpeed();
  // Delay between sequences
  unsigned int interval_delay = randomDelay();

  Servo ranServo = randomServo();

  laserOff();

  switch (sequence){
  case 0:  // Calibrate servos to start position
    calibrate();
    break;

  case 1:  // Move base servo
    setRandomPosition();
    move(servo_base, position[0], position[1], speed);
    break;

  case 2:  // Move top servo (constrain positions)
    setRandomPosition();
    move(servo_top, constrain(position[0], 0, SERVO_TOP_MIN_POS), constrain(position[1], 0, SERVO_TOP_MAX_POS), speed);
    break;

  case 3:  // Move any servo back and fourth
    setRandomPosition();
    move(ranServo, SERVO_TOP_MAX_POS, position[0], speed);
    delay(interval_delay);

    move(ranServo, SERVO_TOP_MIN_POS, position[1], speed);
    delay(interval_delay);

    break;

  default:
    Serial.println("### default sequence ###");
    play(randomGame());
    break;
  }
  delay(interval_delay);


  // Display log information
  printlogHeader();
  log("game: ", sequence);
  log("speed: ", speed); 
  log("delay: ", interval_delay); 
  log("start: ",  position[0]);
  log("end: ", position[1]); 
  printlogFooter();
}













