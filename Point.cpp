#include "Point.h"

//Default Constructor which intializes the Point to (0,0) unless no inputs were given.
Point::Point() {
    X = 0;
    Y = 0;
}

//Non-Default constructor to which the user can set a Point (X,Y)
Point::Point(double x, double y)  { 
    X = x;
    Y = y; 
}
    
//Setter Functions which sets the values for X and Y specifically
void Point::setX(double x) {X = x;}
void Point::setY(double y) {Y = y;}
    
//Getter Functions which return the values for X and Y specifically
double Point::getX() {return X;}
double Point::getY() {return Y;}
    
//Function to return the Coordinate of a point expressed as a String. 
void Point::getCoordinates() {
    std::cout << "(" << X << ", " << Y << ")" << std::endl;
}