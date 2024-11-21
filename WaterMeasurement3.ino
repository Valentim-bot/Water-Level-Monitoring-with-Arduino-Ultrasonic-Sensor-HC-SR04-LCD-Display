#include <LiquidCrystal_I2C.h>
#include <HCSR04.h>

// Pin definitions for the ultrasonic sensor
#define TRIGGER_PIN 8
#define ECHO_PIN 9

double distance_cm, depth; // Variables to store measured distance and calculated depth

// Ultrasonic sensor and LCD initialization
UltraSonicDistanceSensor distanceSensor(TRIGGER_PIN, ECHO_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); // Initialize LCD
  lcd.backlight(); // Turn on LCD backlight
  Serial.begin(9600); // Initialize Serial Monitor
}

void loop() {
  // Measure the distance in centimeters
  distance_cm = distanceSensor.measureDistanceCm();

  // Log the distance to the Serial Monitor
  Serial.print("Measured Distance: ");
  Serial.println(distance_cm);

  if (distance_cm < 17 && distance_cm > 0) { // Only proceed if distance is within a valid range
    depth = 12.90 - distance_cm; // Calculate the depth

    // Update the LCD display
    if (depth >0) {            // Check if no distance is detected
      Serial.println("No distance detected"); // Print a message if no distance is detected
       lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Depth:");
    lcd.setCursor(0, 1);
    lcd.print(depth, 2); // Display the depth with 2 decimal places
    delay(250); // Add a small delay to make the display stable
      
    }
    else {
    // Display a message when no valid distance is detected
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No distance");
    lcd.setCursor(0, 1);
    lcd.print("detected");
  }}

  
}
