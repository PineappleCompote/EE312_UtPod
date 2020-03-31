/*
 * Song.cpp
 * Dilya Anvarbekova and Teddy Hsieh
 *
 * Implementation of the Song class constructor and destructor
 */

#include "Song.h"

using namespace std;

    Song::Song(){
        artist = "";
        title = "";
        size = 0;
    }

    Song::Song(string title){
        this->title = title;
    }

    Song::Song(string _artist, string _title, int _size){
        artist = _artist;
        title = _title;
        size = _size;
    }

    string Song::getTitle() const{
        return title;
    }

    void Song::setTitle(string n) {
        title = n;
    }

    string Song::getArtist() const {
        return artist;
    }

    void Song::setArtist(string n) {
        this->artist = n;
    }

    int Song::getSize() const {
        return size;
    }

    void Song::setSize(int s) {
        this->size = s;
    }

    bool Song::operator<(const Song &rhs) {
        bool lessThan = false;
        if(artist < rhs.artist){
            lessThan = true;
        }
        else if(artist == rhs.artist){
            if(title < rhs.title){
                lessThan = true;
            }
            else if(title == rhs.title){
                if(size < rhs.size){
                    lessThan = true;
                }
            }
        }
        return lessThan;
    }

    bool Song::operator>(const Song &rhs) {
        bool greater = false;
        if(artist > rhs.artist){
            greater = true;
        }
        else if(artist == rhs.artist){
            if(title > rhs.title){
                greater = true;
            }
            else if(title == rhs.title){
                if(size > rhs.size){
                    greater = true;
                }
            }
        }
        return greater;
    }

    bool Song::operator==(const Song &rhs) {
        if(artist == rhs.artist){
            if(title == rhs.title){
                if(size == rhs.size){
                    return true;
                }
            }
        }
        else{
            return false;
        }
    }

    void Song::swap(Song &s) {
        Song temp = s;
        s = *this;
        *this = temp;
    }

    Song::~Song() {
        cout << "Inside the destructor" << endl;
    }