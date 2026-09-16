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
        Movie movie;
        movie.editMovie();
    }
};

void Theater::addShowing(){
    int choice;
    cout << "CHOOSE 1-7: ";
    //print list of movies
    cout << "Which movie is being shown? ";
    if (numMovies < 1){
        cout << "You must have at least one movie befor creating a showing.";
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
    if(numShowings == 0){
        cout << "You have no showings";
    }else{
        Showing showing;
        showing.editShowing();
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
