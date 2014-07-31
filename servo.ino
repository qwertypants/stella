/* Moves one servo using given @start_pos and @end_pos positions
 * Using a delayed loop, this allows for varying @speed */
void move(Servo servo, unsigned int start_pos, unsigned int end_pos, unsigned int speed){
  servo.write(start_pos);
  unsigned int pos;
  // Declare vars outside loop
  if(start_pos >= 90){
    for(pos = start_pos; pos > end_pos; pos--){
      servo.write(pos);
      laserBeam();
      delay(speed);
    }
  }

  if(start_pos <= 90){
    for(pos = start_pos; pos < end_pos; pos++){
      servo.write(pos);
      laserBeam();
      delay(speed);
    }
  }
}

void moveToPoint(Servo servo, unsigned int pos){
  servo.write(pos);
}


// Aligns the servos forward
void calibrate(){
  servo_base.write(90);
  servo_top.write(90);
}

// Attach/Detach servos
void attachServos(){
  if(!servo_base.attached() && !servo_top.attached()){
    servo_base.attach(SERVO_BASE_PIN);
    servo_top.attach(SERVO_TOP_PIN);
  }
}
void detachServos(){
  if(servo_base.attached() && servo_top.attached()){
    servo_base.detach();
    servo_top.detach();
  }
}

