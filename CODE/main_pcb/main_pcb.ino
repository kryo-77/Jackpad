// untested code for main pcb
// Arduino (ESP32 core 3.x)
// Libraries needed: Adafruit NeoPixel
// ESP32 xiao s3
// used ai for as5600 / max98357a beep
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <ESP_I2S.h>

// Pin def
#define LED_PIN    2    // D1/GPIO2 - 74AHCT125 -> WS2812 strip
#define ENUM_PIN   4    // D3/GPIO4 - slot connector J10
#define SDA_PIN    5    // D4/GPIO5 - I2C SDA
#define SCL_PIN    6    // D5/GPIO6 - I2C SCL
#define I2S_DIN    7    // D8/GPIO7 - MAX98357A DIN
#define I2S_BCLK   8    // D9/GPIO8 - MAX98357A BCLK
#define I2S_LRC    9    // D10/GPIO9 - MAX98357A LRC


#define NUM_LEDS     3     // leds present
#define AS5600_ADDR  0x36   // AS5600

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
I2SClass i2s;

// AS5600
int readAngle() {
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(0x0C);                 // RAW ANGLE register
  if (Wire.endTransmission() != 0) return -1;   // -1 = sensor not found
  Wire.requestFrom(AS5600_ADDR, 2);
  if (Wire.available() < 2) return -1;
  int high = Wire.read();
  int low  = Wire.read();
  return ((high << 8) | low) & 0x0FFF;
}

// beep on amp
void beep(int freq, int ms) {
  const int sampleRate = 16000;
  int samples = sampleRate * ms / 1000;
  for (int i = 0; i < samples; i++) {
  
    int16_t s = ((i * freq * 2 / sampleRate) % 2) ? 3000 : -3000;
    i2s.write((uint8_t*)&s, sizeof(s));
  }
}

void setup() {
  Serial.begin(115200);

  // LEDs
  strip.begin();
  strip.setBrightness(40);   
  strip.show();

  // ENUM 
  pinMode(ENUM_PIN, INPUT_PULLUP);

  // I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // I2S audio
  i2s.setPins(I2S_BCLK, I2S_LRC, I2S_DIN);
  if (!i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO)) {
    Serial.println("I2S fail :( )");
  }

  Serial.println("Boot OK");
  beep(880, 200);   // beep beep
}

void loop() {
  //encoder
  int angle = readAngle();

  //slot connector
  bool slotConnected = (digitalRead(ENUM_PIN) == LOW);

  //  Print 
  Serial.printf("angle=%d  slot=%s\n", angle, slotConnected ? "connected" : "empty");

  delay(50);
}