#include <M5Core2.h>
  
void setup() {
  
  // ディスプレイとシリアルとON
  M5.begin(true, false, true);
    
  // スタート
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  
  // タイトル
  M5.Lcd.setCursor(10, 80);
  M5.Lcd.println("QR code + Button");
}
  
void loop() {
  M5.update();
   
  if (M5.BtnA.wasReleased()) {
    // A ボタン
    // https://1ft-seabass.jp/ のQRコードを表示
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.qrcode("https://1ft-seabass.jp/",50,10,220,5);
  } else if (M5.BtnB.wasReleased()) {
    // B ボタン
    // LINE BOT の友達追加 URL の QR コードを表示
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.qrcode("https://line.me/R/ti/p/@XXXXXXXXXX",50,10,220,5);
  } else if (M5.BtnC.wasReleased()) {
    // C ボタン
    // Twitter URL https://twitter.com/1ft_seabass のQRコードを表示
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.qrcode("https://twitter.com/1ft_seabass",50,10,220,5);
  }
}
