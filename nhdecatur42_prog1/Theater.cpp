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
        (*movieArray)->editMovie(); //here
    }
};

void Theater::addShowing(){
    if(numMovies == 0){
        cout << "There are no movies in your list";
    }else if (numShowings == maxShowings){
        cout << "Your showing list is full";
    }else{
        int auditoriumNum;
        int seatsAval;
        float ticketPrice;
        string showTime;
        Movie* title;

        cout << "----------" << title << "----------";

        cout << "Show time (example: 7:30 PM): ";
        cin >> showTime;

        cout << "Auditorium number: ";
        cin >> auditoriumNum;

        cout << "Ticket price: $";
        cin >> ticketPrice;

        cout << "Seats available: ";
        cin >> seatsAval;

        cout << "Showing was added";
        
    }

};

void Theater::editShowing(){
    if(numShowings == 0){
        cout << "You have no showings";
    }else{
        (*showingArray)->editShowing(); //here
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
