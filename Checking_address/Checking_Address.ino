// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address and dimensions (change 0x27 if your address is different)

// void setup() {
//   Serial.begin(9600);
//   Wire.begin(); // Initialize I2C communication
//   lcd.init();  // Initialize the LCD display
//   lcd.backlight(); // Turn on the backlight
//   lcd.setCursor(0, 0);
//   lcd.print("I2C and LCD test");
//   delay(2000);
//   lcd.clear();
// }

// void loop() {
//   byte error, address;
//   int deviceCount = 0;

//   lcd.setCursor(0, 0);
//   lcd.print("Scanning I2C...");
//   delay(500);

//   for(address = 1; address < 127; address++ ) {
//     // The i2c_scanner uses the return value of
//     // the Write.endTransmisstion to see if
//     // a device did acknowledge to the address.
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0) {
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print("I2C device found:");
//       lcd.setCursor(0, 1);
//       lcd.print("Address 0x");
//       if (address < 16) lcd.print("0");
//       lcd.print(address, HEX);
//       delay(2000);
//       deviceCount++;
//     }
//   }

//   if (deviceCount == 0) {
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("No I2C devices");
//     delay(2000);
//   }
// }




#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial port to connect
  Wire.begin(); // Initialize I2C communication
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for(address = 1; address < 127; address++ ) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      deviceCount++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0)
    Serial.println("No I2C devices found\n");

  delay(5000); // Wait 5 seconds for next scan
}
