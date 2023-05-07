#include <M5Core2.h>
  
void setup() {
  
  // ディスプレイとシリアルとON
  M5.begin(true, false, true);
    
  // スタート
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  
  // タイトル
  M5.Lcd.setCursor(10, 40);
  M5.Lcd.println("DRONEBIRD maps");
  M5.Lcd.setTextColor(DARKGREY);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println(" on UNVT Portable");
  M5.Lcd.println(" v.0.63");
  M5.Lcd.setTextSize(3);
  M5.Lcd.println(" ");
  M5.Lcd.println(" ");
  M5.Lcd.println(" ");
  M5.Lcd.println(" ---");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.println(" wi-fi  map  help");
}
  
void loop() {
  M5.update();
   
  if (M5.BtnA.wasReleased()) {
    // A ボタン
    // Wi-Fi アクセス用QRコードを表示
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.qrcode("WIFI:S:dronebird;T:WPA;P:dronebid;;",50,10,220,5);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Wi-Fi");
  } else if (M5.BtnB.wasReleased()) {
    // B ボタン
    // URL の QR コードを表示
    M5.Lcd.fillScreen(DARKCYAN);
    M5.Lcd.qrcode("https://dronebird.org/",50,10,220,5);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Maps");

  } else if (M5.BtnC.wasReleased()) {
    // C ボタン
    // URL の QR コードを表示
    M5.Lcd.fillScreen(DARKGREY);
    M5.Lcd.qrcode("https://github.com/unvt/portable",50,10,220,5);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Help");

  }
}
