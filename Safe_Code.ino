#include <Wire.h>
#include <rgb_lcd.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// RFID pins
#define RST_PIN D3  // GPIO0
#define SS_PIN  D4  // GPIO2

// LCD
rgb_lcd lcd;

// RFID
MFRC522 rfid(SS_PIN, RST_PIN);

// Servo
Servo myServo;
const int servoPin = 15; // GPIO15 = D8 on NodeMCU

// Authorized RFID UID
String allowedUID = "7 30 f0 11"; // Change to your UID

// Servo angles
int openAngle = 0;
int closedAngle = 180;

void setup() {
  // LCD setup
  Wire.begin(D2, D1); // SDA = D2 (GPIO4), SCL = D1 (GPIO5)
  lcd.begin(16, 2);
  lcd.setRGB(0, 128, 255); // Soft blue background
  lcd.print("Scan your card");

  // RFID setup
  SPI.begin();
  rfid.PCD_Init();

  // Serial
  Serial.begin(9600);

  // Servo setup
  myServo.attach(servoPin);
  myServo.write(closedAngle); // Initial position
}

void loop() {
  // Wait for RFID card
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  // Get UID
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i], HEX);
    if (i != rfid.uid.size - 1) uid += " ";
  }

  Serial.println("UID: " + uid);
  lcd.clear();

  if (uid.equalsIgnoreCase(allowedUID)) {
    // ACCESS GRANTED
    lcd.setRGB(0, 255, 0); // Green
    lcd.setCursor(0, 0);
    lcd.print("ACCESS GRANTED");
    lcd.setCursor(0, 1);
    lcd.print("DOOR OPENING");

    myServo.write(openAngle);
    delay(10000); // Wait 10 seconds
    myServo.write(closedAngle);
  } else {
    // ACCESS DENIED
    lcd.setRGB(255, 0, 0); // Red
    lcd.setCursor(0, 0);
    lcd.print("ACCESS DENIED");
    lcd.setCursor(0, 1);
    lcd.print("TRY AGAIN");
  }

  delay(2000);
  lcd.clear();
  lcd.setRGB(0, 128, 255); // Return to soft blue
  lcd.print("Scan your card");

  // Stop reading
  rfid.PICC_HaltA();
}
