/*
Name: Noelle Decatur
file: Theater.cpp
Purpose: define functions for Theater.h and hub for Driver.cpp to go to other areas
*/

using namespace std;
# include <iostream>
# include <string>
# include "Theater.h"


int Theater::getNumMovies(){
    return numMovies;
};

int Theater::getNumShowings(){
    return numShowings;
};

/*
This creats the diffrent movie information and stores them
*/
void Theater::addMovie(){
    if (numMovies >= maxMovies){
        cout << "Sorry, no more movies can be added. You have hit max capacity.";
    }else if (numMovies == maxMovies){
        cout << "Your movie list is full!";
    }else {
        string title;
        int releaseYear;
        int runtimeMinutes;
        string rating;

        cin.ignore();
        cout << "Movie title: ";
        getline(cin, title);

        cout << "Release year: ";
        cin >> releaseYear;

        cout << "Runtime in minutes: ";
        cin >> runtimeMinutes;

        cin.ignore();
        cout << "Rating: ";
        getline(cin, rating);

        movieArray[numMovies] = new Movie(title, releaseYear, runtimeMinutes, rating);
        numMovies++;
        
    }
};
/*
This brings you to the movie.cpp to let you edit the indivdual choises
and checks that you have movies
*/
void Theater::editMovie(){
    if(numMovies == 0){
        cout << "You have no movies";
    }else{
        int choice;
        printMovieNames()
;        cout << "Which movie would you like to edit? ";
        cin >> choice;

        while(!cin || choice < 1 || choice > numMovies){
            cin.clear();
            cin.ignore();
            cout << "Oops! You didn't enter a valid movie number.";
            cout << "\nWhich movie would you like to edit? ";
            cin >> choice;
        }
        (*movieArray)->editMovie();
    }
};

/*
This adds a sowing kinda like how addMovie works but it goes to the Showing.cpp
*/
void Theater::addShowing(){
    if(numMovies == 0){
        cout << "There are no movies in your list";
    }else if (numShowings == maxShowings){
        cout << "Your showing list is full";
    }else{
        int auditoriumNumber;
        int seatsAvalable;
        float ticketPrice;
        string showTime;
        Movie* title;
        
        int choice;
        printMovieNames();
        cout << "\nWhich movie is being shown? ";
        cin >> choice;

        cin.ignore();

        cout << "Show time (example: 7:30 PM): ";
        getline(cin, showTime);

        cout << "Auditorium number: ";
        cin >> auditoriumNumber;

        cout << "Ticket price: $";
        cin >> ticketPrice;

        cout << "Seats available: ";
        cin >> seatsAvalable;

        cout << "Showing was added";
        
        showingArray[numShowings] = new Showing(title, showTime, auditoriumNumber, ticketPrice, seatsAvalable);
        numShowings++;
    }

};

/*
This brings you to the edit showing
*/
void Theater::editShowing(){
    if(numShowings == 0){
        cout << "You have no showings";
    }else{
        (*showingArray)->editShowing(); // directs you to the editShowing
    }
};


/*
These go print the movies and the other showing in there respective .cpp's
*/
void Theater::printMovies(){
    if(numMovies == 0){
        cout << "You have no movies";
    }else{
        for(int i = 0; i < numMovies; i++){
            (*movieArray[i]).printMovie();
        }
    }
};

void Theater::printShowings(){
    if(numShowings == 0){
        cout << "You have no showings";
    }else{
        for(int i = 0; i < numShowings; i++){
            (*showingArray[i]).printShowing();
        }
    }
};

void Theater::printMovieNames(){
    if(numMovies == 0){
        cout << "There are no movies names to print";
    }else{
        for(int i = 0; i < numMovies; i++){
            cout << "\nMovie #" << i + 1 << "   " << (*movieArray[i]).getTitle();
        }
    }
};

void Theater::printShowingNames(){
    if(numMovies == 0){
        cout << "You must have at least one movie before a showing";
    }else{
        for(int i = 0; i < numShowings; i++){
            cout << "\nShowing #" << i + 1 << " " << (*(*showingArray[i]).getMovie()).getTitle() <<(*showingArray[i]).getShowTime();
        }
    }
};
