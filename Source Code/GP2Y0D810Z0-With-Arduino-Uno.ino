#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// GP2Y0D810Z0F sensor pin
const int SENSOR_PIN = 2;

// Initialize LCD (address 0x27, 16 columns, 2 rows)
// If 0x27 doesn't work, try 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize sensor pin
  pinMode(SENSOR_PIN, INPUT);
  
  // Initialize LCD
  lcd.begin();
  lcd.backlight();
  
  // Display startup message
  lcd.setCursor(0, 0);
  lcd.print("Distance Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensor state (LOW = object detected, HIGH = no object)
  int sensorState = digitalRead(SENSOR_PIN);
  
  // Clear LCD
  lcd.clear();
  
  if (sensorState == LOW) {
    // Object detected within 10cm
    lcd.setCursor(0, 0);
    lcd.print("Object Detected");
    lcd.setCursor(0, 1);
    lcd.print("Distance: <10cm");
    
    Serial.print("Status: Object detected | Distance: <10cm");
    Serial.println();
  } else {
    // No object detected
    lcd.setCursor(0, 0);
    lcd.print("No Object");
    lcd.setCursor(0, 1);
    lcd.print("Distance: >10cm");
    
    Serial.print("Status: No object | Distance: >10cm");
    Serial.println();
  }
  
  delay(200); // Small delay for stability
}