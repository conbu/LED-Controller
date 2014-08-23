#include <Adafruit_NeoPixel.h>
#define MAX_VAL 64  // 0 to 255 for brightness
#define DELAY_TIME 20
#define MAX_STRIP 4
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)

Adafruit_NeoPixel strips[4] = {
  Adafruit_NeoPixel(10, 1, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(10, 2, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(10, 3, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(10, 4, NEO_GRB + NEO_KHZ800),
};
 
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < MAX_STRIP; i++) {
    strips[i].begin();
    strips[i].show();
  }
}
 
void loop() {  
  int inputByte = 0;
  inputByte = Serial.available();
  if (inputByte > 3) {
    int line = Serial.read();
    Serial.println(line, DEC);

    int r = Serial.read();
    Serial.println(r, DEC);

    int g = Serial.read();
    Serial.println(g, DEC);

    int b = Serial.read();
    Serial.println(b, DEC);
    
    int line_r = r * MAX_VAL / 255;
    int line_g = g * MAX_VAL / 255;
    int line_b = b * MAX_VAL / 255;
    // Serial.println(line_r, DEC);
    // Serial.println(line_g, DEC);
    // Serial.println(line_b, DEC);
    
    line--;
    uint32_t color = strips[line].Color(line_r, line_g, line_b);
    colorWipe(&strips[line], color, DELAY_TIME);
    delay(5);
    for (int i = 4; i < inputByte; i++) {
      int ch = Serial.read();
    }
  }
  delay(0.2);
}

// Fill the dots one after the other with a color
void colorWipe(Adafruit_NeoPixel* strip, uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i< strip->numPixels(); i++) {
      strip->setPixelColor(i, strip->Color(0, 0, 0));
      strip->show();
      delay(wait);
  }
  for(uint16_t i=0; i< strip->numPixels(); i++) {
      strip->setPixelColor(i, c);
      strip->show();
      delay(wait);
  }
}