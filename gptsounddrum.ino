#include <Adafruit_NeoPixel.h>

// ピンの設定
#define LED_PIN 2      // LEDを接続したピン
#define NUM_LEDS 19    // 使用するLEDの数

// 音声センサのピン設定
#define SENSOR_PIN A0  // 音声センサを接続したアナログピン

// LED設定
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// 音声センサの感度設定
const int THRESHOLD = 500;

// カラー設定
const uint32_t COLORS[] = {
  0xFF0000,  // 赤
  0x00FF00,  // 緑
  0x0000FF,  // 青
  0xFFFF00,  // 黄
  0xFF00FF,  // ピンク
  0x00FFFF   // シアン
};

void setup() {
  Serial.begin(9600);
  
  // LEDの初期化
  leds.begin();
  leds.show();  // 全てのLEDを消灯
  
  // 音声センサのピンを入力モードに設定
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.println(sensorValue);
  
  // 音声センサの値が閾値を超えた場合
  if (sensorValue > THRESHOLD) {
    // LEDをランダムな色に変化させる
    uint32_t color = COLORS[random(0, sizeof(COLORS) / sizeof(COLORS[0]))];
    
    // 全てのLEDに色を設定
    for (int i = 0; i < NUM_LEDS; i++) {
      leds.setPixelColor(i, color);
    }
    leds.show();  // LEDを更新
    delay(100);   // LEDを一定時間表示する
    
    // LEDを消灯
    for (int i = 0; i < NUM_LEDS; i++) {
      leds.setPixelColor(i, 0);
    }
    leds.show();  // LEDを更新
  }
}
