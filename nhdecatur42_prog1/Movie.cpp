/*
    Name of file: Movie.cpp
    Program 1 CSC 1310
    Authour: Noelle Decatur
*/


# include "Movie.h"


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
        cout << "\nWhat movie would you like to edit";
        cout << "1. Title";
        cout << "2. Release Year";
        cout << "3. Runtime";
        cout << "4. Rating";
        cout << "5. Done Editing";
        cout << "CHOOSE 1-5: ";
        cin >> choice;

        while(!cin || choice < 1 || choice > 5){
            if(!cin){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n Oops! I don't think thats right.";
            }
            else
                cout << "\n You didn't enter a number in the range. Try again!";

                cout << "Enter 1-5: ";
                cin >> choice;
        }
        switch(choice){
            case 1:
                cout << "Current title: " << title << endl;
                cout << "New title: ";
                cin >> title;

            case 2:
                cout << "Current title: " << releaseYear << endl;
                cout << "New release year: ";
                cin >> releaseYear;

            case 3:
                cout << "Current title: " << runtimeMinutes << endl;
                cout << "New run time: ";
                cin >> runtimeMinutes;

            case 4: 
                cout << "Current title: " << rating << endl;
                cout << "New rating: ";
                cin >> rating;
                
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
             
