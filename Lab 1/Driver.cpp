/*
	Driver for Course Structure
	LAB 1 CSC 1310
	Authors: April Crockett and Noelle Decatur
	
	Date Created: 1/19/2026
	Date Updated: 8/31/2026
*/

#include "course.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	//Create a pointer to an array of Course pointers called myCourses here
	Course** myCourses; //added

	int numCourses, numSections;
	string name, location;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	
	//Dynamically allocate a new array of pointers to Courses of size numCourses and assign this array to myCourses
	myCourses = new Course* [numCourses]; //added
	
	// Loop for main information
	for (int i=0; i< numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);
		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();
		
		//Call the createCourse function and make sure to assign the returned value to myCourses[i]
		myCourses[i] = createCourse(name, location, numSections, numHours); //added
		
		// loop for course sections
		for(int x=0; x<numSections; x++)
		{
			cout << "\nSECTION " << x+1 << ":\t\t";
			//Read in the string from the user and put in the correct array element of the sections array
			getline(cin, myCourses[i]->sections[x]); //added
			
		}
		cout << "\n*******************************\n";
	}
	
	//print results
	cout << "\n\nThe following are the courses you entered:\n\n";
	for(int i=0; i<numCourses; i++)
	{
		cout << "******************************* COURSE " << (i+1) << "*******************************\n";
		printCourse(myCourses[i]);
	}
	
	//release all dynamically allocated data
	for(int i=0;  i< numCourses; i++)
	{
		destroyCourse(myCourses[i]);
	}
	delete [] myCourses;
	
	cout << endl << endl;
	return 0;
}