/*
Name: Noelle Decatur
file: Theater.h
Purpose: to store class and function calls
*/

#ifndef THEATER_H
#define THEATER_H

using namespace std;
# include <iostream>
# include <iomanip>
# include <string>
# include "Showing.h"
# include "Movie.h"

class Theater {
    private:
        string theaterName;
        Movie** movieArray;
        int numMovies;
        int maxMovies;
        Showing** showingArray;
        int numShowings;
        int maxShowings;
    
    public:
        Theater(string tN, int mM, int mS){
            theaterName = tN;

            numMovies = 0;
            maxMovies = mM;
            
            numShowings = 0;
            maxShowings =  mS;

            movieArray = new Movie*[maxMovies];
            showingArray = new Showing*[maxShowings];
        }
        ~Theater(){ //this will delete anything unnessisary
            for (int i = 0; i < numMovies; i++){
                delete movieArray[i];
            }
            delete movieArray;

            for(int i = 0; i < numShowings; i++){
                delete showingArray[i];
            }
            delete showingArray;
        }

        // functon calls
        int getNumMovies();
        int getNumShowings();

        void addMovie();
        void editMovie();
        void addShowing();
        void editShowing();
        void printMovies();
        void printShowings();
        void printMovieNames();
        void printShowingNames();
        

};

#endif 