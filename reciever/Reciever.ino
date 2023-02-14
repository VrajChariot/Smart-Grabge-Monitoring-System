#include<RH_ASK.h>
#include<SPI.h>

String str_distance;
String str_percentage;
String str_out; 

RH_ASK rf_driver;


void setup() {
  rf_driver.init();
  Serial.begin(9600);
  delay(2000);

}

void loop() {
  uint8_t buf[11];
  uint8_t buflen = sizeof(buf);

  if(rf_driver.recv(buf,&buflen))
  {
    str_out = String((char*)buf);

    for (int i = 0; i < str_out.length(); i++) {
    if(str_out.substring(i, i+1) == ",") {
    str_distance = str_out.substring(0, 1);
    str_percentage = str_out.substring(i+1);
    break;
    }
  }
    Serial.println(str_percentage);
    delay(1000);
 }

} 


