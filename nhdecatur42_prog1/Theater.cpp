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

void Theater::addMovie(){
    if (numMovies >= maxMovies){
        cout << "Sorry, no more movies can be added. You have hit max xapacity.";
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
        cin.ignore();
        printMovieNames();
        cout << "Which movie is being shown? ";
        cin >> choice;

        cout << "Show time (example: 7:30 PM): ";
        getline(cin, showTime);

        cin.ignore();
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

void Theater::editShowing(){
    if(numShowings == 0){
        cout << "You have no showings";
    }else{
        (*showingArray)->editShowing();
    }
};

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
            cout << "\nMovie #" << i + 1 << (*movieArray[i]).getTitle();
        }
    }
};

void Theater::printShowingNames(){
    if(numMovies == 0){
        cout << "You must have at least one movie before a showing";
    }else{
        for(int i = 0; i < numShowings; i++){
            cout << "\nShowing #" << i + 1 << (*(*showingArray[i]).getMovie()).getTitle() <<(*showingArray[i]).getShowTime();
        }
    }
};
