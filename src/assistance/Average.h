

#ifndef AVERAGE_H
#define AVERAGE_H

#define WINDOW_LENGTH 20

class MovingAverage
{
    public:

        // constructor
        MovingAverage();

        // public methods
        void updateWithNewValue(double newValue);
        double getAverage();

    private:
        double _sampleArray[WINDOW_LENGTH];
        uint8_t _currentWriteIndex = 0;
};

#endif
