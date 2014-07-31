// Sending only a HIGH signal effectively turns it off
void laserOff(){
  digitalWrite(LASER_PIN, HIGH);
}
// Rapid HIGH/LOW signals turns beam on
void laserBeam(){
  digitalWrite(LASER_PIN, HIGH);
  delay(5);
  digitalWrite(LASER_PIN, LOW);
}


