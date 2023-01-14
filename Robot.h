#include <iostream>
#include <cmath>
#include "Segment.h"
//#include "Point.h"

//These two libaraies above are used for the printPose() which is used to print a 2D plot for the Robot. 
//Make sure that pbPlots.hpp, pbPlots.cpp, supportLib.hpp and supportLib.cpp are in your directory to make sure it works.
#include "pbPlots.hpp"
#include "supportLib.hpp"

#ifndef ROBOT_H
#define ROBOT_H
using namespace std;

//This class provides represents the chain of segments (root segment and other segments in the chain.)
class Robot {
private:
    int n; //Size of the segment array which indicates the number of segments. It's static as it is used for the entire class and not one particular Segment object. It is initalized to 1 automatically as there is a root segment.
    Segment *temp_segptr; //Temporary Pointer which is used for dynamically increasing/decreasing the Segment array

public:
    Segment *segptr; //Pointer which points to an array of Segment objects in the heap
    Segment root; //This is the root segment of the robot.
    
    Robot();
    void editRoot();
    void addSegment(Segment S);
    void subtractSegment();
    void resetRobot();
    void printSegNumInfo(int num);
    void printPose();
    void editSegment(int num);
    void kinematicAnalysis();
    void printAll();
};

#endif