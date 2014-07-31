// Update the start/end points of servos's position
void setPosition(unsigned int start_pos, unsigned int end_pos){
  position[0] = start_pos;
  position[1] = end_pos;
}

// Update position randomly
void setRandomPosition(){
  setPosition(random(0, SERVO_TOP_MAX_POS), random(0, SERVO_TOP_MAX_POS));
}


