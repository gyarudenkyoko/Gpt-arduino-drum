#include <Servo.h>

// サーボモーターのピン設定
#define SERVO_PIN 9    // サーボモーターを接続したピン

// ドラムのリズムパターン
const int rhythmPatterns[][16] = {
  // パターン1
  {90, 45, 90, 45, 90, 45, 90, 45, 90, 45, 90, 45, 90, 45, 90, 45},
  // パターン2
  {45, 90, 45, 90, 45, 90, 45, 90, 45, 90, 45, 90, 45, 90, 45, 90},
  // パターン3
  {90, 90, 90, 90, 45, 45, 45, 45, 90, 90, 90, 90, 45, 45, 45, 45},
  // 他のパターン...
};

// BPMとテンポの設定
const int BPM = 200;
const int tempo = 60000 / BPM;  // ミリ秒単位のテンポ

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  randomSeed(analogRead(0));  // ランダムシードを設定
}

void loop() {
  // ランダムにリズムパターンを選択
  int patternIndex = random(0, sizeof(rhythmPatterns) / sizeof(rhythmPatterns[0]));

  for (int i = 0; i < 16; i++) {
    // サーボモーターを指定された角度に移動させる
    servo.write(rhythmPatterns[patternIndex][i]);
    
    // ドラムをたたく時間間隔（テンポ）待機する
    delay(tempo);
  }
}
