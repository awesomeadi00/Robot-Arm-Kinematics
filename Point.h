#include <iostream>

#ifndef POINT_H
#define POINT_H
using namespace std;


//This class entails the storage information regarding a specific point/coordinate of the robot arm. 
//It contains information regarding the (X,Y) values. 
class Point {
private: //Contains the coordinate variables of X and Y
    double X;
    double Y;
    
public:
    Point();
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void getCoordinates();
};

#endif
