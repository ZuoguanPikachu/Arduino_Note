
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

  display.drawRect(2, 2, 124, 60, WHITE);


  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(28, 28);
  display.println("Hello World!");

  display.display();
 }

void loop() {

}
