/*
 * Code written By Salar Jaberi 
 * jaberisalar@gmail.com
 * 
 */
const int wet=362;
const int dry=690;

// LED SETUP
int led_pin=13;
int led_pin2=12;
int led_pin3=1;
int led_pin4=10;
int count=0;
int pumpPin = 8;
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 //
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
   pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);
 // delay(9000);
 
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
}
}
void loop() {
 
   int val = analogRead(0); 
   int percentageHumitity= map(val,wet,dry,100,0); // gets a range from 0 - 100 map is used to check the val wet and dry
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Moisture Level: ");
  display.println("%");
  Serial.print(percentageHumitity);
  Serial.println("%");
  display.display(); 
  
if (percentageHumitity>100){
   count=0;
  Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity);
  Serial.println("%");
  digitalWrite(led_pin2,HIGH);
  delay(500);
  digitalWrite(led_pin,HIGH);
  delay(500);
  digitalWrite(led_pin3,HIGH);
  delay(500);
  digitalWrite(led_pin4,HIGH);
  delay(1000);
  digitalWrite(led_pin2,LOW);
  delay(500);
  digitalWrite(led_pin,LOW);
  delay(500);
  digitalWrite(led_pin3,LOW);
  delay(500);
  digitalWrite(led_pin4,LOW);
  delay(500);
}
else if (percentageHumitity<100&&percentageHumitity>80){
  count=0;
  Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity);
  Serial.println("%");
  digitalWrite(led_pin,HIGH);
  digitalWrite(led_pin2,HIGH);
  digitalWrite(led_pin3,HIGH);
  digitalWrite(led_pin4,HIGH);
}
else if (percentageHumitity<80&&percentageHumitity>70){
  count=0;
  Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity);
  Serial.println("%");
  digitalWrite(led_pin,HIGH);
  digitalWrite(led_pin3,HIGH);
  digitalWrite(led_pin4,HIGH);
  
}
else if (percentageHumitity<70&&percentageHumitity>60){
  count=0;
  Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity);
  Serial.println("%");
  digitalWrite(led_pin3,HIGH);
  digitalWrite(led_pin4,HIGH);
  
  
}
else if (percentageHumitity<60&&percentageHumitity>50){
  count=0;
  Serial.print("Moisture Level poo: ");
  Serial.print(percentageHumitity);
  Serial.println("%");
  digitalWrite(led_pin4,HIGH);
}
 else if (percentageHumitity<50){
  count++;
  Serial.println(count);
  Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity);
  Serial.println("%");
  digitalWrite(led_pin2,HIGH);
  digitalWrite(led_pin,HIGH);
  digitalWrite(led_pin3,HIGH);
  digitalWrite(led_pin4,HIGH);
  delay(350);
  digitalWrite(led_pin2,LOW);
  digitalWrite(led_pin,LOW);
  digitalWrite(led_pin3,LOW);
  digitalWrite(led_pin4,LOW);
if(count<2){
  digitalWrite(pumpPin, LOW);
   delay(2500);
   digitalWrite(pumpPin, HIGH);
   Serial.println(count);
}
   if(count>150){
    count=0;
   }
delay(1000);
} 
  delay(1000);
}
