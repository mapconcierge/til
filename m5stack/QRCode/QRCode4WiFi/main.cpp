#include <M5Core2.h>
#include <WiFi.h>
#include <qrcode.h>

// 以下にSSID、パスワード、暗号化方式を設定してください。
const char* SSID = "your_SSID_here";
const char* password = "your_password_here";
const char* encryptiontype = "WPA2"; // 例: "WPA2", "WPA", "WEP", "OPEN"

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_WHITE);

  String qrData = "WIFI:S:" + String(SSID) + ";T:" + String(encryptiontype) + ";P:" + String(password) + ";;";
  displayQRCode(qrData);
}

void loop() {
}

void displayQRCode(String data) {
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qrcodeData, 3, ECC_LOW, data.c_str());

  uint32_t qrSize = qrcode.size * 5; // QRコードの拡大倍率
  uint32_t x = (M5.Lcd.width() - qrSize) / 2;
  uint32_t y = (M5.Lcd.height() - qrSize) / 2;

  M5.Lcd.fillRect(x-3, y-3, qrSize+6, qrSize+6, TFT_BLACK);
  M5.Lcd.drawRect(x-3, y-3, qrSize+6, qrSize+6, TFT_WHITE);

  for (uint8_t i = 0; i < qrcode.size; i++) {
    for (uint8_t j = 0; j < qrcode.size; j++) {
      if (qrcode_getModule(&qrcode, i, j)) {
        M5.Lcd.fillRect(x + i * 5, y + j * 5, 5, 5, TFT_BLACK);
      } else {
        M5.Lcd.fillRect(x + i * 5, y + j * 5, 5, 5, TFT_WHITE);
      }
    }
  }
}
