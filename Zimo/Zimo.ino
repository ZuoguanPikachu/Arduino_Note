#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// // 连接到 I2C（SDA、SCL 引脚）的 SSD1306 显示器的声明
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  // clear the screen
  display.clearDisplay();

  static const unsigned char PROGMEM ai[]={0x00,0x08,0x01,0xFC,0x7E,0x10,0x22,0x10,0x11,0x20,0x7F,0xFE,0x42,0x02,0x82,0x04,0x7F,0xF8,0x04,0x00,0x07,0xF0,0x0A,0x10,0x11,0x20,0x20,0xC0,0x43,0x30,0x1C,0x0E};
  static const unsigned char PROGMEM ni[]={0x08,0x80,0x08,0x80,0x08,0x80,0x11,0xFE,0x11,0x02,0x32,0x04,0x34,0x20,0x50,0x20,0x91,0x28,0x11,0x24,0x12,0x24,0x12,0x22,0x14,0x22,0x10,0x20,0x10,0xA0,0x10,0x40};
  static const unsigned char PROGMEM yo[]={0x02,0x20,0x02,0x20,0xF2,0x20,0x94,0x3C,0x95,0x44,0x9F,0x44,0x92,0x84,0x92,0x24,0x94,0x14,0x9F,0x94,0xF4,0x04,0x90,0x04,0x01,0x84,0x0E,0x04,0x04,0x28,0x00,0x10};

  display.drawBitmap(40, 21, ai, 16, 16, WHITE);
  display.drawBitmap(56, 21, ni, 16, 16, WHITE);
  display.drawBitmap(72, 21, yo, 16, 16, WHITE);
  display.display();
 }

void loop() {

}