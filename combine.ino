#include <DS3231.h>
const int relayEnable =2;
const int sensorPin =A0;
const int tresholdMax=800;
const int tresholdMin =10;
int Relay = 4;

DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 12; //SET TIME TO ON RELAY (24 HOUR FORMAT)
const int OnMin = 26;
const int OffHour = 12; //SET TIME TO OFF RELAY
const int OffMin = 27;

void setup() {
   pinMode(relayEnable, OUTPUT);
   pinMode(sensorPin, INPUT);
   Serial.begin(9600);
  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
  Serial.println("Soil Moisture Level:");
   delay(1000);

  
}
void loop() {
  t = rtc.getTime();
  int sensorValue =analogRead(sensorPin);
sensorValue = map(sensorValue, tresholdMax, tresholdMin, 0, 100);
Serial.print("Moisture:");
Serial.println(sensorValue);
Serial.println("%");
if (sensorValue < 30)
{
  digitalWrite(relayEnable, HIGH);
  Serial.println("Relay ON");
}
else
{
  digitalWrite(relayEnable, LOW);
  Serial.println("Relay OFF");
}
delay(1000);
Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  delay (1000);
  
  if(t.hour == OnHour && t.min == OnMin){
    digitalWrite(Relay,HIGH);
    Serial.println("LIGHT ON");
    }
    
    else if(t.hour == OffHour && t.min == OffMin){
      digitalWrite(Relay,LOW);
      Serial.println("LIGHT OFF");
    }
}
  
