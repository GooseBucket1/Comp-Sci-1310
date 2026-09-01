#ifndef COURSE_H
#define COURSE_H


using namespace std; 
#include <iostream>


// structure for course informatin
struct Course {
    string name;
    string location;
    int numSections;
    int numHours;
    string* sections;
};

/// function calls

Course* createCourse (string, string, int, int);
void destroyCourse(Course*);
void printCourse(Course*);


#endif