#include "Segment.h"

//Default Constructor which intializes the Segment with (0,0) start point, Length as 1, Angle as 0 radians and (1,0) end point.
Segment::Segment() {
    start.setX(0);
    start.setY(0);
    length = 1;
    angle = 0;
    end.setX(1);
    end.setY(0);
}

//Non-Default constructor to which the user can set parameters for a segment (start point, length and angle)
Segment::Segment(double xstart, double ystart, double l, double a) {
    start.setX(xstart);
    start.setY(ystart);
    length = l;
    angle = a;
    EndPoint(xstart, ystart, l, a);
}

//Next 3 functions are Setter functions for the Start Point, Length and Angle respectively. Once they are called, they automatically call the End Point function which calculates and changes the end point automatically.
void Segment::setStartPoint(double xstart, double ystart)  {
    start.setX(xstart);
    start.setY(ystart);
    double l = length;
    double a = angle;
    EndPoint(xstart, ystart, l, a);
}

void Segment::setLength(double l)  {
    length = l;
    int xstart = start.getX();
    int ystart = start.getY();
    double a = angle;
    EndPoint(xstart, ystart, l, a);
}

void Segment::setAngle(double a)  {
    angle = a;
    int xstart = start.getX();
    int ystart = start.getY();
    double l = length;
    EndPoint(xstart, ystart, l, a);
}

//Getter functions for the Length, Angle, Start Point and End Point values.
double Segment::getLength() {return length;}
double Segment::getAngle() {return angle;}
double Segment::getStartX() {return start.getX();}
double Segment::getStartY() {return start.getY();}
double Segment::getEndX() {return end.getX();}
double Segment::getEndY() {return end.getY();}

//Function to print out all of the information regarding a Segment. This prints out the startpoint, the length, the angle of rotation and endpoint of a segment. 
void Segment::printSegmentInfo() {
    cout << "The start point coordinates are: (" << start.getX() << ", " << start.getY() << ")." << endl;
    cout << "The length of the segment is: " << length << endl;
    cout << "The angle of rotation of the segment is: " << angle << endl;
    cout << "The end point coordinates are: (" << end.getX() << ", " << end.getY() << ")." << endl;
    cout << "\n";
}