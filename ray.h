//
// Created by Brian Dolle on 3/23/18.
//

#ifndef RUNGECLASSTEST_RAY_H
#define RUNGECLASSTEST_RAY_H

#include "Coords.h" // includes the previously defined class "Coords"

class ray {  // defines the class ray
public:      // chooses the public axis

    // other initial conditions

    Coords coords_;     // calling another class named Coords

    // Defining member variables
    double h_;
    double sigma =10.0;
    double r=28.0;
    double b=8.0/3.0;
    int steps_;

    ray(double t, double x, double y, double z, double tfinal, int steps); // constructor with parameter inputs
    ~ray(); // destructor

    // Defining member functions
    void step();
    void runray();
    double xdotfunc(Coords coords);
    double ydotfunc(Coords coords);
    double zdotfunc(Coords coords);

}; // ends class

#endif //RUNGECLASSTEST_RAY_H
