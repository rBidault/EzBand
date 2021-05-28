#include <Arduino_APDS9960.h>

#define LEDR        (22u)
#define LEDG        (23u)
#define LEDB        (24u)

int sensorValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  APDS.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (APDS.proximityAvailable()){;
    sensorValue = APDS.readProximity();
    if(sensorValue==0){
      delay(5000);
      sensorValue = APDS.readProximity();
      if(sensorValue==0){
        digitalWrite(LEDG, HIGH);
        delay(250);
        digitalWrite(LEDG, LOW);
        delay(250);
        digitalWrite(LEDG, HIGH);
        delay(250);
        digitalWrite(LEDG, LOW);
        //funcao para esteperar voz e gesto
      }
    }
  }
  Serial.println(sensorValue);
}
