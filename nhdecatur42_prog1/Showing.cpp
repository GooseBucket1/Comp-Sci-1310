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
    int choice;

    do {
        cout << "\n";
        cout << "1. Show Time";
        cout << "2. Auditorium Number";
        cout << "3. Ticket Price";
        cout << "4. Seats Available";
        cout << "5. Done Editing";
        cout << "CHOOSE 1-5: ";
        cin >> choice;

        while(!cin || choice < 1 || choice > 5){
            if(!cin){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n Oops! I don't think thats right.";
            }
            else
                cout << "\n You didn't enter a number in the range. Try again!";

                cout << "Enter 1-5: ";
                cin >> choice;
        }
        switch(choice){
            case 1:
                cout << "Current show time: " << showTime << endl;
                cout << "New show time: ";
                cin >> showTime;

            case 2:
                cout << "Current auditorium number: " << auditoriumNumber << endl;
                cout << "New auditorium number: ";
                cin >> auditoriumNumber;

            case 3:
                cout << "Current ticket price: " << ticketPrice << endl;
                cout << "New ticket price: ";
                cin >> ticketPrice;

            case 4: 
                cout << "Current seats available: " << seatsAvailable << endl;
                cout << "New seats available: ";
                cin >> seatsAvailable;
                
        }

    }while(choice != 5);
    cout << "end of showimg editing\n";
};

void Showing::printShowing(){
    cout << "\nMovie: ";
    cout << "Show Time: " << showTime << endl;
    cout << "Auditorium: " << auditoriumNumber << endl;
    cout << "Ticket Price: " << ticketPrice << endl;
    cout << "Seats Available: " << seatsAvailable << endl;
};