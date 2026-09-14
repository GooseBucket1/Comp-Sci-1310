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
    }else {
        cout << "Movie title: ";
        Movie::setTitle;

        cout << "Release year: ";
        Movie::setReleaseYear;

        cout << "Runtime in minuets: ";
        Movie::setRuntimeMinutes;

        cout << "Rating: ";
        Movie::setRating;

    }
};

void Theater::editMovie(){
    Movie movie;
    movie.editMovie();
};

void Theater::addShowing(){
    int choice;
    cout << "CHOOSE 1-7: ";
    //print list of movies
    cout << "Which movie is being shown? ";
    if (numMovies < 1){
        cout << "You muct have at least one movie befor creating a showing.";
    }else {
        cout << "Which movie is being shown? ";
        cin >> choice;
            while(!cin || choice < numMovies || choice > numMovies){
                if(!cin){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Oops! wrong data type.";
                }else
                    cout << "Oops! You didn't enter a valid movie number.";
                cout << "\nWhich movie is being shown? ";
                cin >> choice;
            } 
    }
    // store all this showing info
    cout << "Show time (example: 7:30 PM): ";
        Showing::setShowTime;
    cout << "Auditorium number: ";
        Showing::getAuditoriumNumber;
    cout << "Ticket price: $";
        Showing::getTicketPrice;    
    cout << "Seats available: ";
        Showing::getSeatsAvalable;
    cout << "Showing was added";

};

void Theater::editShowing(){
    Showing showing;
    showing.editShowing();
};

void Theater::printMovies(){
    Movie movie;
    movie.printMovie();
};

void Theater::printShowings(){
    Showing showing;
    showing.printShowing();
};

void Theater::printMovieNames(){
    
};

void Theater::printShowingNames(){
    
};
