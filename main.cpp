// Main File //

#include <iostream>
#include "Coords.h"
#include "ray.h"

using namespace std;

int main() {

    // initial conditions

    double t0 = 0.0;
    double tf = 1000.0;
    double x0 = 1.0;
    double y0 = 3.0;
    double z0 = 2.0;
    int steps = 100000;

    // call the constructor to make an instance called "trajectory1" with intial coniditions
    ray trajectory1(t0, x0, y0, z0, tf, steps);

    // this calls the member function "runray()" from the class "ray"
    trajectory1.runray();

    return 0;
}