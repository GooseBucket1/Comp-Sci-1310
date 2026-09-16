/*
    Name of file: Movie.cpp
    Program 1 CSC 1310
    Authour: Noelle Decatur
*/


# include "Movie.h"
# include <iostream>


void Movie::setTitle(string t){
    title = t;
};

void Movie::setReleaseYear(int y){
    releaseYear = y;
};

void Movie::setRuntimeMinutes(int m){
    runtimeMinutes = m;
};

void Movie::setRating(string r){
    rating = r;
};

string Movie::getTitle() {
    return title;
};

int Movie::getReleaseYear() {
    return releaseYear;
};

int Movie::getRuntimeMinutes(){
    return runtimeMinutes;
};

string Movie::getRating() {
    return rating;
};

void Movie::editMovie() {
    int choice;

    do {
        cout << "\nWhat would you like to edit";
        cout << "\n1. Title";
        cout << "\n2. Release Year";
        cout << "\n3. Runtime";
        cout << "\n4. Rating";
        cout << "\n5. Done Editing";
        cout << "\nCHOOSE 1-5: ";
        cin >> choice;

        while(!cin || choice < 1 || choice > 5){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nOops thats not a valild inpit.";
            cout << "Please choose 1-5: ";
            cin >> choice;
        }
        

        switch(choice){
            case 1:
                cin.ignore();
                cout << "Current title: " << title << endl;
                cout << "New title: ";
                getline(cin, title, '\n');
                break;

            case 2:
                cout << "Current releasr year: " << releaseYear << endl;
                cout << "New release year: ";
                cin >> releaseYear;
                while(!cin){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "That is not a year please enter a valid year: ";
                    cin >> releaseYear;
                }

            case 3:
                cout << "Current runtime: " << runtimeMinutes << endl;
                cout << "New run time: ";
                cin >> runtimeMinutes;
                while(!cin){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "That is not a year please enter a valid year: ";
                    cin >> releaseYear;
                }

            case 4: 
            cin.ignore();
                cout << "Current rating: " << rating << endl;
                cout << "New rating: ";
                getline(cin, rating, '\n');
                break;  
        }

    }while(choice != 5);
    cout << "end of movie editing\n";

};



void Movie::printMovie(){
    cout << "\nTitle: " << title << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Runtime: " << runtimeMinutes << endl;
    cout << "Rating: " << rating << endl;
};
             
