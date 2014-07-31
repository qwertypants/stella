// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<ring.numPixels(); i++) {
    ring.setPixelColor(i, c);
    ring.show();
    delay(wait);
    // Stop the light sequence
    if(i >= ring.numPixels() - 1){
      return;
    }
  }
}

// This sequence get interrupted if toggle_state
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    // Activates the interrupt to stop rainbow sequence
    if(toggle_state == LOW){
      for(i=0; i<ring.numPixels(); i++) {
        ring.setPixelColor(i, Wheel((i+j) & 255));
      }
      ring.show();
      delay(wait);
    } 
    else {
      break;
    }
  }
}

// Generate a random color
uint32_t randomColor(){
  byte r,g,b;
  r = random(0,255);
  g = random(0,255);
  b = random(0,255);
  return ring.Color(r,g,b);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return ring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return ring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return ring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
