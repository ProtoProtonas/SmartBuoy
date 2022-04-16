
#include <stdint.h>
#include "Average.h"

MovingAverage::MovingAverage()
{
    for(uint8_t i = 0; i < WINDOW_LENGTH; i++)
    {
        _sampleArray[i] = 0;
    }
}

void MovingAverage::updateWithNewValue(double newValue)
{
    if(_currentWriteIndex < WINDOW_LENGTH)
    {
        _sampleArray[_currentWriteIndex] = newValue;
    }

    // update write index
    _currentWriteIndex++;
    if(_currentWriteIndex >= WINDOW_LENGTH)
    {
        _currentWriteIndex = 0;
    }
}


double MovingAverage::getAverage()
{
    double average = 0;
    double sum = 0;

    for(uint8_t i = 0; i < WINDOW_LENGTH; i++)
    {
        sum += _sampleArray[i];
    }
    average = sum / WINDOW_LENGTH;

    return average;
}
