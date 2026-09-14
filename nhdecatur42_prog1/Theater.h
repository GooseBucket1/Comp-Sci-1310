#ifndef THEATER_H
#define THEATER_H

using namespace std;
# include <iostream>
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
        Theater(){
            theaterName = "";
            numMovies = 0;
            maxMovies = 0;
            numShowings = 0;
            maxShowings = 0;
        }
        Theater(string tN, Movie** m, int nM, int mM, Showing** s, int nS, int mS){
            theaterName = tN;
            numMovies = nM;
            maxMovies = mM;
            numShowings = nS;
            maxShowings =  mS;
        };

        int getNumMovies() const;
        int getNumShowings() const;

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