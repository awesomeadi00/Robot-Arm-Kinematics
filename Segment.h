#include <iostream>
#include "Point.h"
#include <cmath>

#ifndef SEGMENT_H
#define SEGMENT_H
using namespace std;

//This class entails all of the information regarding a specific segment of the robot arm. 
//It contains information regarding the start point, length, angle of rotation and end point of a segment.
class Segment{
private: 
    double length;  //Length of a segment
    double angle;   //Angle of rotation of a segment
    Point start;    //Start point of a segment
    Point end;      //End pointo of a segment

    //This function automatically calculates the endpoint of a segment through the input parameters of the start coordinate, length and angle.
    void EndPoint(double xstart, double ystart, double l, double a) {
        
        if(a == M_PI_2) {
            end.setX(start.getX());
            end.setY((l*1)+start.getY());
        }
        
        else if(a == M_PI) {
            end.setX((l*-1)+start.getX());
            end.setY(start.getY());
        }
        
        else if(a == 3*M_PI_2) {
            end.setX(start.getX());
            end.setY((l*-1)+start.getY());
        }
        
        else if(a == 2*M_PI) {
            end.setX((l*1)+start.getX());
            end.setY(start.getY());
        }
        
        else {
            end.setX((l*cos(a))+start.getX());
            end.setY((l*sin(a))+start.getY());
        }
    }
    friend class Robot;

public: 
    Segment();
    Segment(double xstart, double ystart, double l, double a);
    void setStartPoint(double xstart, double ystart);
    void setLength(double l);
    void setAngle(double a);
    double getLength();
    double getAngle();
    double getStartX();
    double getStartY();
    double getEndX();
    double getEndY();
    void printSegmentInfo();
};

#endif
