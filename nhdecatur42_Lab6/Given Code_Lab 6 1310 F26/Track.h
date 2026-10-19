#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>

using namespace std;

class Track{
    private:
        string track_id;
        int popularity;
        string artist;
        string track_name;
    
    public:
        Track(){
            track_id = "NULL";
            popularity = 0;
            artist = "NULL";
            track_name = "NULL";
        }
        Track(string id, int pop, string art, string tName){
            track_id = id;
            popularity = pop;
            artist = art;
            track_name = tName;
        }
        friend ostream &operator << (ostream &strm, Track &a){
            strm << "Track ID: " << a.track_id << "\n"
            << "Popularity: " << a.popularity << "\n"
            << "Artist: " << a.artist << "\n"
            << "Track Name: " << a.track_name << "\n";
            return strm;
        }

};


#endif