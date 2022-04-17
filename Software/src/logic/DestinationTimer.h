

#ifndef DESTINATIONTIMER_H
#define DESTINATIONTIMER_H

class DestinationTimer
{
    public:

        // constructor
        DestinationTimer();

        // class variables

        // public methods
        bool isItTimeToGoHome();

        void updateTime(unsigned long int currentMillis);

        void updateTimeWhenBuoyPositionWasReached();

    private:
        // private variables
        unsigned long int _timeWhenBuoyDestinationWasReached = 0;
        unsigned long int _currentMillis = 0;

        bool _destinationReachedTimeSetFlag = false;

        // private methods

        // private objects

};

#endif
