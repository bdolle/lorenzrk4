//
// Created by Brian Dolle on 3/23/18.
//

#include <iostream>
#include "ray.h"
#include <cmath>
#include<fstream>

using namespace std;

ray::ray(double tinit, double xinit, double yinit, double zinit, double tfinal, int steps) {

    // constructor - this one gives initial conditions and makes step size

    h_ = (tfinal - tinit)/steps;
    coords_.t_ = tinit;
    coords_.x_ = xinit;
    coords_.y_=yinit;
    coords_.z_=zinit;
    steps_ = steps;
}

ray::~ray() {
    // destructor
}

void ray::runray() {
    for(int i=0; i<steps_; i++){
        step();
     // this is just to print   cout<<coords_.t_ <<"  " <<coords_.x_ <<"  "<<coords_.y_<<"  "<<coords_.z_<<endl;

        if(steps_%100==0){

            // writes to file
            ofstream fout;
            fout.open("lorenz.dat", ios::out | ios::app);
            fout<<coords_.x_ << " "<<coords_.y_ << " "<< coords_.z_ << ",";
        } // closes if
    } // closes i loop
} // closes runray

void ray::step(){

    // defines all the k's for the RK4 method in 3 coordinate axes
    // and passes the functions below an intermediate set of coordinates

    double kx1, ky1, kz1, kx2, ky2, kz2, kx3, ky3, kz3, kx4, ky4, kz4;
    Coords intercoords;

    kx1 = h_ * xdotfunc(coords_);
    ky1 = h_ * ydotfunc(coords_);
    kz1 = h_ * zdotfunc(coords_);
    intercoords.x_ = coords_.x_ + kx1/2.0;
    intercoords.y_ = coords_.y_ + ky1/2.0;
    intercoords.z_ = coords_.z_ + kz1/2.0;


    kx2 = h_ * xdotfunc(intercoords);
    ky2 = h_ * ydotfunc(intercoords);
    kz2 = h_ * zdotfunc(intercoords);
    intercoords.x_ = coords_.x_ + kx2/2.0;
    intercoords.y_ = coords_.y_ + ky2/2.0;
    intercoords.z_ = coords_.z_ + kz2/2.0;


    kx3 = h_ * xdotfunc(intercoords);
    ky3 = h_ * ydotfunc(intercoords);
    kz3 = h_ * zdotfunc(intercoords);
    intercoords.x_ = coords_.x_ + kx3;
    intercoords.y_ = coords_.y_ + ky3;
    intercoords.z_ = coords_.z_ + kz3;


    kx4 = h_ * xdotfunc(intercoords);
    ky4 = h_ * ydotfunc(intercoords);
    kz4 = h_ * zdotfunc(intercoords);


    coords_.x_ = coords_.x_ + kx1/6.0 + kx2/3.0 + kx3/3.0 + kx4/6.0;
    coords_.y_ = coords_.y_ + ky1/6.0 + ky2/3.0 + ky3/3.0 + ky4/6.0;
    coords_.z_ = coords_.z_ + kz1/6.0 + kz2/3.0 + kz3/3.0 + kz4/6.0;
    coords_.t_ = coords_.t_ + h_;

}

// Defines the functions originally given to us

double ray::xdotfunc(Coords localcoords) {

    return sigma*(localcoords.y_-localcoords.x_);
}

double ray::ydotfunc(Coords localcoords) {

    return -localcoords.x_*localcoords.z_ + r*localcoords.x_ - localcoords.y_;
}

double ray::zdotfunc(Coords localcoords) {

    return localcoords.x_*localcoords.y_ - b*localcoords.z_;
}