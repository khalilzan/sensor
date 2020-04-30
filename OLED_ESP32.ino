/*

This is a code of OLED screen 128x64 using ESP32 to draw
value.

Pins:
 * GND = GND
 * VCC = 5V
 * SCL = D22
 * SDA = D21
 
Made by: Khalil Zanklo
Last modification: 5/01/2019

*/

#include <WiFi.h>//library allows ESP32 board to connect to the internet.
#include <Wire.h>//Library allowing to communicate with I2C
#include <Adafruit_GFX.h> //Graphics core library
#include <Adafruit_SSD1306.h> //OLED driver for monochrome display 128x64
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Declaration Wifi things and client address
const char* ssid = "YOURNETWORK"; 
const char* password =  "YOURPASSWORD";

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/

//Start of setup
void setup() {

  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 0x3C allocation failed"));
    for(;;);
  }

  display.setTextSize(1);//Set text size
  display.setTextColor(WHITE);//Set text color
  display.setCursor(0, 10);//(x, y)
  display.clearDisplay();// Clear the buffer
  
  display.drawBitmap(0, 0, myBitmap, 128, 64, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();
  delay(3000);//3 sec delay for logo purpose
  display.clearDisplay();// Clear the buffer
  
  //display wifi status on the OLED screen 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  display.clearDisplay();// Clear the buffer
  
  Serial.println("Connecting to WiFi..");
  display.println("Connecting to WiFi..");
  display.display(); // Print everything that was set previously
  delay(1000); // This delay is needed to let the display to initialize
  }
  
  display.clearDisplay(); // Clear the buffer
  //display wifi status on the OLED screen as connected
  Serial.println("Connected!!");
  display.println("Connected!!");
  display.display(); // Print everything that was set previously
  delay(2000);
  display.clearDisplay();  // Clear the buffer

}
 
  void displayContent(){
  
  display.setFont(&FreeMono9pt7b);  //Set a custom font
  display.setTextSize(1);//Set text size
  display.setTextColor(WHITE);//Set color (black or white in our case)
  display.setCursor(0, 10);//(x,y)
  
  // Clear the buffer
  display.clearDisplay();
  
  //draw Rounded Rectangles
  display.drawRoundRect(85, 0, 42, 15, 8, WHITE);//Draw rounded rectangle (x, y, width, height, color) 
  display.drawRoundRect(85, 16, 42, 15, 8, WHITE);//Draw rounded rectangle (x, y, width, height, color)
  display.drawRoundRect(85, 32, 42, 15, 8, WHITE);//Draw rounded rectangle (x, y, width, height, color)
  display.setCursor(0, 10);  // (x,y)
  display.println("Temp");// Text to print
  display.println("Hum");// Text to print
  display.println("Water");// Text to print
  
  display.setCursor(87, 12);  // (x,y)
  display.println(1);  // Text or value to print
  display.setCursor(87, 27);  // (x,y)
  display.println(1);  // Text or value to print
  display.setCursor(87, 42);  // (x,y)
  display.println(1);  // Text or value to print
  display.display();  // Print everything that was set previously
  delay(150);//Delay at the end of this loop
  }
  
//Start of loop 
void loop() {
  displayContent();
}
