#ifndef SHOWING_H
#define SHOWING_H

using namespace std;
# include <iostream>
# include <string>

class Showing {
    private:
        Movie* movie;
        string showTime;
        int auditoriumNumber;
        float ticketPrice;
        int seatsAvailable;
    
    public:
        Showing(){
            showTime = "";
            auditoriumNumber = 0;
            ticketPrice = 0;
            seatsAvailable = 0; 
        }

        Showing(string s, int a, float p, int sA){
            showTime = s;
            auditoriumNumber = a;
            ticketPrice = p;
            seatsAvailable = sA; 
        };

        void setMovie();
        void setShowTime();
        void setAuditoriumNumber();
        void setTicketPrice();
        void setSeatsAvailable ();
        Movie* getMovie();
        string getShowTime();
        int getAuditoriumNumber();
        float getTicketPrice();
        int getSeatsAvalable();
        void editShowing();
        void printShowing();

};

#endif 