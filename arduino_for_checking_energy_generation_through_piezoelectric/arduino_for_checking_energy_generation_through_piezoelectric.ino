#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


const int lcdAddress = 0x27;

// Set the LCD dimensions (16 columns and 2 rows)
const int lcdCols = 16;
const int lcdRows = 2;

// Create an LCD object
LiquidCrystal_I2C lcd(lcdAddress, lcdCols, lcdRows);

// Define the limits
const int minValue = 0;
const int maxValue = 1023;

// Define the minimum and maximum values for the scaled data
const float scaledMinValue = 0;  // Define the minimum value for the scaled data
const float scaledMaxValue = 10;   // Define the maximum value for the scaled data


int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); // Corrected to OUTPUT
  // Initialize the LCD
  lcd.init();
  // // Turn on the backlight
  lcd.backlight();
  // Print a message to the LCD
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue); // Print sensor value to serial monitor
  
  if (sensorValue > 0) {
    digitalWrite(LED_BUILTIN, sensorValue/500);
    // Scale the value to the range between 0 and 5
    float scaledValue = map(sensorValue, minValue, maxValue, scaledMinValue * 100, scaledMaxValue * 100) / 100.0;

    // Update the LCD display
    lcd.clear(); // Clear the previous content
    lcd.setCursor(0, 0); // Set cursor to first row
    lcd.print("Voltage : "); // Print label
    lcd.print(scaledValue); // Print scaled  value
    lcd.print(" volt");

    // Delay to control update rate
    delay(500); // Adjust as needed depending on your application
  } else {
    digitalWrite(LED_BUILTIN, LOW);
     // Update the LCD display
    lcd.clear(); // Clear the previous content
    lcd.setCursor(0, 0); // Set cursor to first row
    lcd.print("Voltage : "); // Print label
    lcd.print(0); // Print scaled  value
    lcd.print("volt");

    // Delay to control update rate
    delay(500); // Adjust as needed depending on your application
  }
}




