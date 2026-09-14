using namespace std;
# include <iostream>
# include <string>
# include "Theater.h"


int Theater::getNumMovies() const{
    return numMovies;
};

int Theater::getNumShowings() const{
    return numShowings;
};

void Theater::addMovie(){

    if (numMovies >= maxMovies){
        cout << "Sorry, no more movies can be added. You have hit max xapacity.";
    }else {
        cout << "Movie title: ";
        cin >> (Movie).title;

        cout << "Release year: ";
        cin >> releaseYear;

        cout << "Runtime in minuets: ";
        cin >> runtimeMinutes;

        cout << "Rating: ";
        cin >> rating;

    }
};

void Theater::editMovie(){
    Movie.editMovie();
};

void Theater::addShowing(){

};

void Theater::editShowing(){
    Showing showing;
    showing.editShowing();
};

void Theater::printMovies(){
    Movie.printMovie();
};

void Theater::printShowings(){

};

void Theater::printMovieNames(){

};

void Theater::printShowingNames(){
    
};
