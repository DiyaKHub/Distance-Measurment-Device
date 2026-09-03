#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int Trig_PIN = 7; // BLUE
const int Echo_PIN = 6; // GREEN

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin (115200); // Setting speed that computer connects with circut
  pinMode (Trig_PIN, OUTPUT);
  pinMode (Echo_PIN, INPUT);

  
  lcd.init();
  lcd.backlight();
  lcd.setCursor (0, 0);
  lcd.print("DIYA KRISHA HaHa");
}

void loop() {

  digitalWrite (Trig_PIN, LOW);               // Starts off - prevents floating
  delayMicroseconds(2);                       // Waits for 2 seconds
  digitalWrite (Trig_PIN, HIGH);              // Turns on - sends a pulse in ECHO pin
  delayMicroseconds (10);                     // Gives some time to get a pulse back - ONLY FIRST PULSE, NOT SECOND
  digitalWrite (Trig_PIN, LOW);
  
  long duration = pulseIn (Echo_PIN, HIGH);   // Reads just the FIRST PULSE- sends a pulse
  
  float distance = (duration * 0.0343 ) / 2;  // d = vt / 2
  distance = distance + 0.2;
  
  
  Serial.println ("Distance: ");
  Serial.print (distance);
  Serial.println (" cm");
  delay (100); 

  lcd.setCursor(0,1);  // Set cursor to first column of second row
  lcd.print("                "); // Print blanks to clear the row
  lcd.setCursor(0,1);   // Set Cursor again to first column of second row
  lcd.print ("Dist.: ");
  lcd.print(distance); // Print measured distance
  lcd.print(" cm");

  delay (1000); // Helps the LCD clear before printing the next value

}
