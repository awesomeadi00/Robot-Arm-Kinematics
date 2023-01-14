#include <iostream>
#include <cmath>       
#include <sstream>
#include <string>

#include "Point.h"      
#include "Segment.h"    
#include "Robot.h"     
using namespace std;

void listCommands(); 


void listCommands() {
    cout << "List of available Commands:" << endl
        << "root                 : Edit the features of the root segment." << endl
        << "add                  : Add another segment at the end of the chain." << endl
        << "remove               : Remove the segment at the end of the chain." << endl
        << "reset                : Resets the entire robot." << endl
        << "print segment        : Prints features of Segment <number> from the chain." << endl
        << "edit segment         : Edits the features of Segment <number> from the chain" << endl
        << "print pose           : Prints the entire Robot Arm (png in directory)" << endl
        << "kinematics           : Calculates the End Effector of the Robot" << endl
        << "help                 : Display the list of available commands" << endl
        << "exit                 : Exit the Program" << endl;
}

int main() {
    Robot R; //Already set up Robot object called R ready for the user.
    double x, y, length, angle;
    int num; 
    string command, str_angle;

    cout << endl;
    cout << "==========================================" << endl;   
    cout << "Welcome to 2D Robot Arm Kinematics Solver!" << endl;
    cout << "==========================================" << endl;   
    listCommands();
        
    do {    
        cout << endl;
        cout << ">";
        getline(cin, command);    

        //If/Else Conditions for each of the Commands
        if(command == "root" or command == "r") {R.editRoot();}
        
        else if(command == "add" or command == "a") {
        cout << "Enter the length of the segment: ";
            cin >> length;

            cout << "Enter the angle of rotation of the segment: ";
            cin >> str_angle;
            
            if(str_angle == "pi") {angle = M_PI;}
            else if(str_angle == "pi/2") {angle = M_PI_2;}
            else if(str_angle == "3pi/2") {angle = 3*M_PI_2;}
            else if(str_angle == "2pi") {angle = 2*M_PI;}
            else {angle = stod(str_angle);}

            Segment S(x, y, length, angle);
            R.addSegment(S);
        }

        else if(command == "remove" or command == "rm") {R.subtractSegment();}
        else if(command == "reset" or command == "r") {
            R.resetRobot();
            cout << "The robot arm has been reset! All segments have collapsed to the x-axis!" << endl;}
            
        else if(command == "print segment" or command == "ps") {
            cout << "Which segment would you like to printInfo?: ";
            cin >> num;
            R.printSegNumInfo(num);}

        else if(command == "edit segment" or command == "es") {
            cout << "Which segment would you like to edit?: ";
            cin >> num;
            R.editSegment(num);}

        else if(command == "print pose" or command == "pp") {R.printPose();}
        else if(command == "kinematics" or command == "k") {R.kinematicAnalysis();}
        else if(command == "help" or command == "h") {listCommands(); }
        else if(command == "exit") {break; }
        else {cout << "Invalid Command!" << endl;}

        fflush(stdin);

    } while(true);     
    return(0);
}

/*
============================================
                User Guide:
============================================
The Robot has already been initialized as "R".  
When inputting angles, they are expressed in radians, hence please type the following: 
- "0" = 0
- "pi" = π
- "pi/2" = π/2
- "3pi/2" = 3π/2
- "2pi" = 2π
- Or whichever other value you wish (expressed in radians).
 */
