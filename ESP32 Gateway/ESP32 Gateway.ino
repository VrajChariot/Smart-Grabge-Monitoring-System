#define BLYNK_DEVICE_NAME "ekachraDaan centra"
#define BLYNK_TEMPLATE_ID "TMPLnXPufnxg"
#define BLYNK_TEMPLATE_NAME "ekachraDaan centra"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include<SoftwareSerial.h>
SoftwareSerial mySerial(D5,D6);//rx,tx pins
const int trigPin = D2;
const int echoPin = D1;
WidgetLED led1(V1); // Green led
WidgetLED led2(V2); // Orange led
WidgetLED led3(V3); // Red led

long duration;
float ref_distance; 
float distance2; 
float percentage; 
float distance_sub;

void ultrasonic()
{
  int msg = mySerial.readStringUntil('/r').toInt();
  Serial.print(msg);
  WidgetLED led1(V1);
  WidgetLED led2(V2);
  WidgetLED led3(V3);
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
  //rural dustbin
  Blynk.virtualWrite(V0, msg);
  if (msg<=25) {
  led1.on();
  led2.off();
  led3.off();
  }
  else if (msg>25 && msg<=65) {
  led1.on();
  led2.off();
  led3.off();  
  }
  else {
  Blynk.logEvent("dustbin_full");
  led1.off();
  led2.on();
  led3.off();
  }
}
void setup()
{
  Serial.begin(115200);
  mySerial.begin(9600);
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
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{ 
  BlynkEdgent.run();
  ultrasonic();
}
