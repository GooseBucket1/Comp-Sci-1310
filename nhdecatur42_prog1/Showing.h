/*
Name: Noelle Decatur
file: SHowing.h
Purpose: to store class and function calls
*/

#ifndef SHOWING_H
#define SHOWING_H

using namespace std;
# include <iostream>
# include <iomanip>
# include <string>
# include "Movie.h"

// class for showing this is where everything is stored
class Showing {
    private:
        Movie* movie;
        string showTime;
        int auditoriumNumber;
        float ticketPrice;
        int seatsAvailable;
    
    public:
        Showing(){
            // this is just defalt if nothing is there it will just leave it blank
            showTime = "";
            auditoriumNumber = 0;
            ticketPrice = 0.00;
            seatsAvailable = 0; 
        }

        Showing(Movie* m, string s, int a, float p, int sA){
            movie = m;
            showTime = s;
            auditoriumNumber = a;
            ticketPrice = p;
            seatsAvailable = sA; 
        }

        // all function calls
        void setMovie(Movie* m);
        void setShowTime(string s);
        void setAuditoriumNumber(int a);
        void setTicketPrice(float p);
        void setSeatsAvailable(int sA);

        Movie* getMovie();

        string getShowTime();
        int getAuditoriumNumber();
        float getTicketPrice();
        int getSeatsAvalable();

        void editShowing();
        void printShowing();

};

#endif 