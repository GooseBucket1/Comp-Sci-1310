# include "Showing.h"

void Showing::setMovie(){
// add something here
};

void Showing::setShowTime(string s){
    showTime = s;
};

void Showing::setAuditoriumNumber(int a){
    auditoriumNumber = a;
};

void Showing::setTicketPrice(float p){
    ticketPrice = p;
};

void Showing::setSeatsAvailable (int sA){
    seatsAvailable = sA;
};

Movie* Showing::getMovie(){
    return movie;
};

string Showing::getShowTime(){
    return showTime;
};

int Showing::getAuditoriumNumber(){
    return auditoriumNumber;
};

float Showing::getTicketPrice(){
    return ticketPrice;
};

int Showing::getSeatsAvalable(){
    return  seatsAvailable;
};

void Showing::editShowing(){
    
};

void Showing::printShowing(){
    cout << "\nMovie: ";
    cout << "Show Time: " << showTime << endl;
    cout << "Auditorium: " << auditoriumNumber << endl;
    cout << "Ticket Price: " << ticketPrice << endl;
    cout << "Seats Available: " << seatsAvailable << endl;
};