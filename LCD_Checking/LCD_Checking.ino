#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address (typically 0x27 for 16x2 or 20x4 LCDs)
const int lcdAddress = 0x27;

// Set the LCD dimensions (16 columns and 2 rows)
const int lcdCols = 16;
const int lcdRows = 2;

// Create an LCD object
LiquidCrystal_I2C lcd(lcdAddress, lcdCols, lcdRows);

void setup() {
  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  // Print a message to the LCD
  lcd.print("Hello, World!");
}

void loop() {
  // Your main code here
  lcd.print("Hello, World!");
  delay(10000);
}

// OR

// #include <Wire.h>  // Include the Wire library for I2C communication
// #include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library

// // Set the LCD address and dimensions (change 0x27 if your address is different)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup() {
//   // Initialize the serial communication for debugging
//   Serial.begin(9600);

//   // Initialize the I2C communication and LCD
//   Wire.begin();
//   lcd.init();
//   lcd.backlight(); // Turn on the backlight (optional)

//   // Print a message to the serial monitor
//   Serial.println("LCD Display Test");
// }

// void loop() {
//   // Clear the LCD screen
//   lcd.clear();

//   // Set the cursor to the first column of the first row
//   lcd.setCursor(0, 0);

//   // Print a message on the LCD display
//   lcd.print("Hello, Arduino!");

//   // Set the cursor to the first column of the second row
//   lcd.setCursor(0, 1);

//   // Print another message on the LCD display
//   lcd.print("I2C Test");

//   // Wait for a moment before clearing the display and repeating
//   delay(2000);
// }

