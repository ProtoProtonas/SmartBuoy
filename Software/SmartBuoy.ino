#include "src/logic/Navigator.h"
#include "src/logic/MotorController.h"
#include "src/assistance/Global.h"
#include "src/assistance/PinDefines.h"


bool has50msPassed = false;
bool hasOneSecondPassed = false;
unsigned long last50msMillis = 0.0;
unsigned long lastOneSecondMillis = 0.0;
unsigned long currentMillis = 0.0;


Navigator navigator;
MotorController motorController;

void manageTiming() 
{
    currentMillis = millis();
    if (currentMillis - last50msMillis >= 50) 
    {
        last50msMillis = currentMillis;
        has50msPassed = true;
        digitalWrite(LED1, LOW);
    }
    if (currentMillis - lastOneSecondMillis >= 1000) 
    {
        lastOneSecondMillis = currentMillis;
        hasOneSecondPassed = true;
    }
}

void setup() 
{
    pinMode(LED1, OUTPUT);
}

void loop() {
    if (has50msPassed) 
    {
        navigator.updateHeadingToTarget();

        if ((navigator.getDistanceToTarget() >= global.targetDistanceError) &&
            (navigator.isGPSLocked())) 
        {
            motorController.updateMotorsByHeading(navigator.getHeadingToTarget());
        } 
        else 
        {
            motorController.cutMotors();
        }

        has50msPassed = false;
        digitalWrite(LED1, HIGH);
    }

    if (hasOneSecondPassed) 
    {
        // update GPS and cut motors if in range
        navigator.updateDistanceToTarget(currentMillis);

        // recalculate magnetic heading and gps distance to target
        hasOneSecondPassed = false;
        digitalWrite(LED1, LOW);
    }

    manageTiming();
}
