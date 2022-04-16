#include <math.h>
#include <stdint.h>
#include "Global.h"


Global global;


Global::Global()
{
    // constructor
}

double Global::degreesToRadians(double degreeInput)
{
    return degreeInput * atan(1) / 45;
}

double Global::radiansToDegrees(double radianInput)
{
    return radianInput * 45 / atan(1);
}
