const int wet=417;
const int dry=613;
int led_pin=13;
int led_pin2=12;
int led_pin3=11;
int led_pin4=10;
int count=0;

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

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
}
  
}
void loop() {
 
  int val = analogRead(0); 
   float voltage = val * (5.0 / 1023.0);
   int percentageHumitity= map(val,wet,dry,100,0); // gets a range from 0 - 100 map is used to check the val wet and dry

if (percentageHumitity>100){

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Moisture Level: ");
  display.println("%");
display.print("VOLTAGE READING-> ");
display.print(voltage);
display.println(" Volts");

  display.display(); 
  
 
}
 
if (percentageHumitity<10){
  digitalWrite(led_pin,LOW);
     Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Im Thirsty!");
  Serial.println("---------------------------------");
 display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Moisture Level: ");
  display.print(percentageHumitity); //print the value to serial port
  display.println("%");
  display.println("Im Thirsty!");
  display.print("VOLTAGE READING-> ");
display.print(voltage);
display.println(" Volts");

  display.display(); 
   digitalWrite(led_pin2,HIGH);
}

else if (percentageHumitity>10&&percentageHumitity<75){
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  digitalWrite(led_pin2,LOW);
     Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Im at a good Level thank you!");
  Serial.println("---------------------------------");
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Moisture Level: ");
  display.print(percentageHumitity); //print the value to serial port
  display.println("%");
  display.println("Im at a good Level thank you!");
  display.print("VOLTAGE READING-> ");
display.print(voltage);
display.println(" Volts");

  display.display(); 
   digitalWrite(led_pin2,HIGH);
  digitalWrite(led_pin,HIGH);
}

else if (percentageHumitity>75&&percentageHumitity<85){
 
  digitalWrite(led_pin,LOW); // resets the LED
   digitalWrite(led_pin4,LOW);
   Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Processing Water Change... Im good <3");
  Serial.println("---------------------------------");

display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Moisture Level: ");
  display.print(percentageHumitity); //print the value to serial port
  display.println("%");
  display.println("Processing Water Change... Im good <3");
  display.print("VOLTAGE READING-> ");
display.print(voltage);
display.println(" Volts");

  display.display(); 




  
  count++;
  if (count<25){
    digitalWrite(led_pin4,HIGH);
  delay(1000);
  digitalWrite(led_pin3,HIGH);
  delay(1000);
  digitalWrite(led_pin,HIGH);
  delay(1000);
  digitalWrite(led_pin2,HIGH);
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
  if (count>5&&count<=25){
    digitalWrite(led_pin4,HIGH);
  delay(3000);
  digitalWrite(led_pin3,HIGH);
  delay(3000);
  digitalWrite(led_pin,HIGH);
  delay(3000);
  digitalWrite(led_pin2,HIGH);
  delay(3000);
  digitalWrite(led_pin2,LOW);
  delay(1500);
  digitalWrite(led_pin,LOW);
  delay(1500);
  digitalWrite(led_pin3,LOW);
  delay(1500);
  digitalWrite(led_pin4,LOW);
  delay(1500);
  }
  if (count>26){
  digitalWrite(led_pin,HIGH);
  digitalWrite(led_pin2,LOW);
 /// digitalWrite(led_pin,LOW);
  digitalWrite(led_pin3,LOW);
  digitalWrite(led_pin4,LOW);
  }
}
 else if (percentageHumitity>85){
     Serial.print("Moisture Level: ");
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Thanks for water, Processing.");
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Moisture Level: ");
  display.print(percentageHumitity); //print the value to serial port
  display.println("%");
  display.println("Thanks for water, Processing.");
  display.print("VOLTAGE READING-> ");
display.print(voltage);
display.println(" Volts");

  display.display(); 

  digitalWrite(led_pin4,HIGH);
  digitalWrite(led_pin3,HIGH);
  digitalWrite(led_pin,HIGH);
  digitalWrite(led_pin2,HIGH);
  delay(1000);
  digitalWrite(led_pin2,LOW);
  digitalWrite(led_pin,LOW);
  digitalWrite(led_pin3,LOW);
  digitalWrite(led_pin4,LOW);
   delay(1000);
    digitalWrite(led_pin2,HIGH);
    delay(500);
    digitalWrite(led_pin,HIGH);
     delay(500);
    digitalWrite(led_pin3,HIGH);
    delay(500);
    
}


  delay(1000);
}
