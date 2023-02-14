#include<RH_ASK.h>
#include<SPI.h>

const int trigPin = 8;
const int echoPin = 9;

long duration;
float ref_distance; 
float distance2; 
float percentage; 
float distance_sub;

String str_distance;
String str_percentage;
String str_out;

RH_ASK rf_driver;

void ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance2 = duration * 0.034 / 2;
  distance_sub = ref_distance-distance2;
  percentage = distance_sub/ref_distance*100; //formula to calculate the percentage for ultrasonic sensor
  Serial.print("Percentage: ");
  Serial.println(percentage);
}

void setup() {
  rf_driver.init();
  Serial.begin(9600);
  pinMode(34, INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  ref_distance = duration * 0.034 / 2; //formula to calculate the distance for ultrasonic sensor
  Serial.print("Distance: ");
  Serial.println(ref_distance);
  delay(500); 
}

void loop() {
  delay(2000);
  ultrasonic();

  str_distance = String(distance2);
  str_percentage = String(percentage);

  str_out = str_distance + "," + str_percentage;
  static char *msg = str_out.c_str();
  
  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();

}
