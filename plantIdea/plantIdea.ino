const int wet=612;
const int dry=881;
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() {
 
  int val = analogRead(0); 
  
   int percentageHumitity= map(val,wet,dry,100,0); // gets a range from 0 - 100 map is used to check the val wet and dry

if (percentageHumitity<25){
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Im Thirsty!");
}

else if (percentageHumitity>25&&percentageHumitity<60){
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Im at a good Level thank you!");
}

else if (percentageHumitity>60&&percentageHumitity<80){
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Processing Water Change... Im good <3");
}
 else if (percentageHumitity>80){
  Serial.print(percentageHumitity); //print the value to serial port
  Serial.println("%");
  Serial.println("Thanks for water, Processing.");
}


  delay(1000);
}
