#include "Navigator.h"
#include "MotorController.h"

#define LED1 D0
#define LED2 D4

bool has50msPassed = false;
bool hasOneSecondPassed = false;
unsigned long last50msMillis = 0.0;
unsigned long lastOneSecondMillis = 0.0;
unsigned long currentMillis = 0.0;

double targetDistanceError = 5.0;

Navigator navigator;
MotorController motorController;

void manageTiming()
{
  currentMillis = millis();
  if(currentMillis - last50msMillis >= 50)
  {
    last50msMillis = currentMillis;
    has50msPassed = true;
    digitalWrite(LED1, LOW);
  }
  if(currentMillis - lastOneSecondMillis >= 1000)
  {
    lastOneSecondMillis = currentMillis;
    hasOneSecondPassed = true;
    digitalWrite(LED2, LOW);
  }
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Serial connection initialized");
}

void loop() {
  if(has50msPassed)
  {
    // update compass and motor stuff

    // update compass readout
    navigator.updateHeadingToTarget();
    
    // get desired heading
    // update motor outputs according to the heading
    
    if((navigator.getDistanceToTarget() >= targetDistanceError) &&
       (navigator.isGPSLocked()))
    {
      motorController.updateMotorsByHeading(navigator.getHeadingToTarget());
    }
    else
    {
      motorController.cutMotors(); // cut motors
    }

//    Serial.println("50ms");
    has50msPassed = false;
    digitalWrite(LED1, HIGH);
  }

  if(hasOneSecondPassed)
  {
    // update GPS and cut motors if in range
    navigator.updateDistanceToTarget();
    
    // recalculate magnetic heading and gps distance to target
    
//    Serial.println("One second");
    hasOneSecondPassed = false;
    digitalWrite(LED2, HIGH);
  }

  manageTiming();
  
}
