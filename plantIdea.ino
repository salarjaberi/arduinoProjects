/*
 * Code written By Salar Jaberi 
 * jaberisalar@gmail.com
 * 
 */
const int wet=307;
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
  //Serial.begin(115200);
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
   float voltage = val * (5.0 / 1023.0);
   int percentageHumitity= map(val,wet,dry,100,0); // gets a range from 0 - 100 map is used to check the val wet and dry
  int lightval = analogRead(A1);
  delay(250);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,2);
  // Display static text
   display.println("Plant Name: Jerome ");
   display.println(" ");
   display.print("Light Sensor...");
   display.print(lightval);
   display.println("ohm");
   display.print("Voltage... ");
   display.print(voltage);
   display.println(" V"); 
   display.print("Moisture Level...");
  display.print(percentageHumitity);
  display.println("%");
  
if (percentageHumitity>105){
  display.println("Check sensor...");
   count=0;
}
else if (percentageHumitity<105&&percentageHumitity>80){
 display.println("Status...Very Healthy");
  count=0;
}
else if (percentageHumitity<80&&percentageHumitity>70){
  display.println("Condtion...Healthy");
  count=0;  
}
else if (percentageHumitity<70&&percentageHumitity>60){
  display.println("Condtion...Amazing");
  count=0;
}
else if (percentageHumitity<60&&percentageHumitity>50){
  display.println("Condtion...Optimal");
  count=0;
}
else if (percentageHumitity<50){
display.println("Condtion...Water Soon");
}

display.print("Pump Cycle...");
display.println(count); 


display.display(); 

count++;

if (percentageHumitity<50){
if(count<2){
 display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,1);
  display.println("ENGANGING PUMP...");
  display.setCursor(0,20);
  display.println("SENSOR CHECK");
  display.setCursor(10,30);
  display.println(" ");
  display.print("DRY->  ");
  display.println(dry);
  display.print("WET->  ");
  display.println(wet);
  display.print("Result->  ");
  display.println(val);
  display.display(); 
  delay(8000);
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.println("WATERING PLANT ");
  display.setTextColor(WHITE);
  display.setCursor(10,30);
  display.println("PLS WAIT <3");
  display.display(); 
   digitalWrite(pumpPin, LOW);
   delay(5000);
   digitalWrite(pumpPin, HIGH);
   Serial.println(count);
}
   if(count>100){
    
    count=0;
   }
delay(1000);
}
  delay(1000);
}
