

#ifndef GLOBAL_H
#define GLOBAL_H

class Global
{
  public:
  
    // constructor
    Global();

    // public methods
    double degreesToRadians(double degreeInput);
    double radiansToDegrees(double radianInput);
};

extern Global global;

#endif
