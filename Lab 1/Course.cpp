#include <iostream>
#include <string>
#include "Course.h"
using namespace std;


// will create a new course struct dynamically 
Course* createCourse (string name, string location, int numSections, int numHours){
    Course* myCourse = new Course;
    (*myCourse).name = name;
    (*myCourse).location = location;
    (*myCourse).numSections = numSections;
    (*myCourse).numHours = numHours;
    (*myCourse).sections = new string[numSections];
    
    return myCourse;

}

void destroyCourse (Course* myCourse){
    delete [] myCourse;
}

// this prints the course(s) information 
void printCourse(Course* myCourse){
                                    // these goes and grabs the different course information
    cout << "Course Name:\t\t" << (*myCourse).name << endl;
    cout << "Course Location:\t" << (*myCourse).location << endl;
    cout << "Course Hours:\t\t" << (*myCourse).numHours << endl;
    cout << "Course Sections:\t" << (*myCourse).numSections << endl;

    for(int i = 0; i < (*myCourse).numSections; i++){
        cout << "\t\t\t" << (*myCourse).sections[i] << endl;
    }
    
    cout << "\n";
}


