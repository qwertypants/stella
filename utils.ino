// Log to serial output
void log(String msg, int val){
  Serial.println(msg + val);
}


void showFreeMemory(){
  Serial.print("free memory: ");
  Serial.println(freeMemory());
}

// Return a random servo
boolean servoPick = 0;
Servo randomServo(){
  Servo servos[] = {
    servo_base, servo_top    };
  boolean pick = servoPick;
  servoPick = !servoPick;
  return servos[pick];
}

void printlogHeader(){
  Serial.println("_____________________________");
  Serial.println("");
  Serial.println("                         *   ");
}

void printlogFooter(){
  Serial.println("                      (`.-,')");
  Serial.println("                    .-'     ;");
  Serial.println("                _.-'   , `,-");
  Serial.println("          _ _.-'     .'  /._");
  Serial.println("        .' `  _.-.  /  ,'._;)");
  Serial.println("       (       .  )-| (");
  Serial.println("        )`,_ ,'_,'  /_;)");
  Serial.println("('_  _,'.'  (___,))");
  Serial.println(" `-:;.-'");
}

