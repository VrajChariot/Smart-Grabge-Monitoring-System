// PID : PID457 | TEAM ID : TM002720 | IOT GARBAGE MONITORING SYSTEM | 
#define BLYNK_TEMPLATE_ID "TMPLCcgc6lKw"
#define BLYNK_DEVICE_NAME "ekachraDaan"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

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
  Blynk.virtualWrite(V0, percentage);
  if (percentage<=25) {
  led3.on();
  led2.off();
  led1.off();
  }
  else if (percentage>25 && percentage<=65) {
  led2.on();
  led1.off();
  led3.off();  
  }
  else {
  Blynk.logEvent("dustbin_full");
  led3.off();
  led1.on();
  led2.off();
  }
}
void setup()
{
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
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
  ultrasonic();
}
