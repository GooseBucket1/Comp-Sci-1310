#ifndef MOVIE_H
#define MOVIE_H

using namespace std;
# include <iostream>
# include <iomanip>
# include <string>

class Movie {
    private:
        string title;
        int releaseYear;
        int runtimeMinutes;
        string rating;
    
    public:
        Movie(){
            title = "";
            releaseYear = 0;
            runtimeMinutes = 0;
            rating = "";
        }

        Movie(string t, int y, int m, string r){
            title = t;
            releaseYear = y;
            runtimeMinutes = m;
            rating = r;
        }
        
        void setTitle(string t);
        void setReleaseYear(int y);
        void setRuntimeMinutes(int m);
        void setRating(string r);

        string getTitle();
        int getReleaseYear();
        int getRuntimeMinutes();
        string getRating();

        void editMovie(); 
        void printMovie();
};

#endif 