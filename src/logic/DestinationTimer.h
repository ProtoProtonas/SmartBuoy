

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

    
  private:
    // private variables
    unsigned long int _timeOfGPSLock = 0;
    unsigned long int _timeWhenFirstDestinationWasReached = 0;

    unsigned long int _timeSinceStart = 0;

    // private methods

    // private objects

};

#endif
