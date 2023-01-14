#include "Robot.h"
#include <vector>
#include <iomanip>
#define P 10

//Constructor: initializes the root segment and the segptr array of Segment objects (first element as root.)
Robot::Robot() {
    //Initialize the root segment:
    root.setStartPoint(0, 0);
    root.setLength(1);
    root.setAngle(0);

    //Initialize the segptr array
    n = 1;
    segptr = new Segment[n];
    segptr[0] = root; 
}

//Edit Root: This function allows the user to edit the features of the root segment.
void Robot::editRoot() {
    double x, y, length, angle;
    string str_angle;

    cout << "Enter the X coordinate of the root: ";
    cin >> x;

    cout << "Enter the Y coordinate of the root: ";
    cin >> y;

    cout << "Enter the length of the root: ";
    cin >> length;

    cout << "Enter the angle of rotation of the root: ";
    cin >> str_angle;

    if(str_angle == "pi") {angle = M_PI;}
    else if(str_angle == "pi/2") {angle = M_PI_2;}
    else if(str_angle == "3pi/2") {angle = 3*M_PI_2;}
    else if(str_angle == "2pi") {angle = 2*M_PI;}
    else {angle = stod(str_angle);}

    root.setStartPoint(x, y);
    root.setLength(length);
    root.setAngle(angle);
    segptr[0] = root;

    cout << endl;
    cout << "Edits successfully made! Here is the new root segment information: " << endl;
    segptr[0].printSegmentInfo();
}

//Add Segment: This dynamically increases the size of the array by 1 and adds the Segment the user created in the main to the array.
void Robot::addSegment(Segment S) {
    temp_segptr = new Segment[n+1];
    for(int i=0; i<n; i++) {
        temp_segptr[i] = segptr[i];
    }
    n++;
    delete[] segptr;
    segptr = temp_segptr;
    temp_segptr = NULL;
    
    segptr[n-1] = S;
    segptr[n-1].setStartPoint(segptr[n-2].getEndX(), segptr[n-2].getEndY());

    cout << endl;
    cout << "Segment added to the chain! Here is the segment information:" << endl;
    segptr[n-1].printSegmentInfo();
}

//Subtract Segment: This dynamically decreases the size of the array by 1 and removes the last Segment of the segment array.
void Robot::subtractSegment() {
    if(n == 1) {
        cout << "Cannot remove the root segment!" << endl; 
    }
    
    else {
        temp_segptr = new Segment[n-1];
        for(int i=0; i<n-1; i++) {
            temp_segptr[i] = segptr[i];
        }
        n--;
        delete[] segptr;
        segptr = temp_segptr;
        temp_segptr = NULL;

        cout << "Last segment added has been removed!" << endl;
    }
}

//Reset Robot: This sets all of the Y values of each point/joint on the Robot to 0 so the robot collapses to the X axis.
void Robot::resetRobot() {
    for(int i=0; i<n; i++) {
        segptr[i].start.setY(0);
        segptr[i].end.setY(0);
    }
}

//This function will print out the segment information of a specific segment: 
void Robot::printSegNumInfo(int num) {
    if(num >= n or num <= 0) {cout << "This segment number is not currently on the Robot Chain" << endl;}
    else {segptr[num-1].printSegmentInfo();}
}

//Function to print out the pose of the robot into a PNG file called "Plot.png"
void Robot::printPose() {
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    
    vector<double> x, y;
    for (int i = 0; i < n; i++) {
        x.push_back(segptr[i].start.getX());
        y.push_back(segptr[i].start.getY());
    }
    x.push_back(segptr[n-1].end.getX());
    y.push_back(segptr[n-1].end.getY());
           
    DrawScatterPlot(imageRef, 600, 400, &x, &y);

    vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, "Plot.png");
    DeleteImage(imageRef->image);
    
    cout << "Robot has been printed!" << endl;
    cout << "Please check your directory for 'Plot.png'" << endl;
    cout << endl;
    cout << "Here is the full orientation of every segment on the Robot: " << endl;
    printAll();

}

//Function to retreive the End Effector of the robot. It simply takes the last segment and retreives the end point of that segment.
void Robot::kinematicAnalysis() {
    double EndEffectorX, EndEffectorY;
    
    EndEffectorX = segptr[n-1].getEndX();
    EndEffectorY = segptr[n-1].getEndY();
    
    cout << "The end effector of this Robot is: (" << EndEffectorX << ", " << EndEffectorY << ")." << endl;
}

//This Function will print all the descriptions for each segment on the Robot chain.
void Robot::printAll() {
    int set;
    cout << "\e[1m";
    cout << "+-------------+---------------------+-----------+----------+-------------------+" << endl;
    cout.setf(ios::right);
    cout << "|" << setw(11) << "Segments:" << setw(3) << "|" << setw(19) << "Start Coordinate:" << setw(3) 
    << "|" << setw(9) << "Length:" << setw(3) << "|" << setw(8) << "Angle:" << setw(3) << "|" << setw(17) << 
    "End Coordinate:" << setw(3) << "|" << endl;
    cout << "+-------------+---------------------+-----------+----------+-------------------+" << endl;

    cout << fixed << setprecision(2) << "\e[0m";
    for(int i=0; i<n; i++) {
        if(i == 0) {
            cout << "|" << setw(8) << "Root" << setw(6) << "|";  
            
            if(segptr[i].start.getX() < 0 and segptr[i].start.getY() < 0) {set = 4;}
            else if(segptr[i].start.getX() < 0 or segptr[i].start.getY() < 0) {set = 5;}
            else {set = 6;}
            cout << setw(set) << "(" << segptr[i].start.getX() << ", " << segptr[i].start.getY() << ")" << setw(5) << "|";

            cout << setw(8) << segptr[i].getLength() << setw(4) << "|";
            cout << setw(7) << segptr[i].getAngle() << setw(4) << "|"; 
            
            if(segptr[i].end.getX() < 0 and segptr[i].end.getY() < 0) {set = 3;}
            else if(segptr[i].end.getX() < 0 or segptr[i].end.getY() < 0) {set = 4;}
            else {set = 5;}
            cout << setw(set) << "(" << segptr[i].end.getX() << ", " << segptr[i].end.getY() << ")" << setw(4) << "|" << endl;
            cout << "+-------------+---------------------+-----------+----------+-------------------+" << endl;
        }

        else {
            cout << "|" << setw(10) << "Segment " << i << setw(3) << "|";  
            
            if(segptr[i].start.getX() < 0 and segptr[i].start.getY() < 0) {set = 4;}
            else if(segptr[i].start.getX() < 0 or segptr[i].start.getY() < 0) {set = 5;}
            else {set = 6;}
            cout << setw(set) << "(" << segptr[i].start.getX() << ", " << segptr[i].start.getY() << ")" << setw(5) << "|";

            cout << setw(8) << segptr[i].getLength() << setw(4) << "|";
            cout << setw(7) << segptr[i].getAngle() << setw(4) << "|"; 
            
            if(segptr[i].end.getX() < 0 and segptr[i].end.getY() < 0) {set = 3;}
            else if(segptr[i].end.getX() < 0 or segptr[i].end.getY() < 0) {set = 4;}
            else {set = 5;}
            cout << setw(set) << "(" << segptr[i].end.getX() << ", " << segptr[i].end.getY() << ")" << setw(4) << "|" << endl;
            cout << "+-------------+---------------------+-----------+----------+-------------------+" << endl;
        }
    }
}