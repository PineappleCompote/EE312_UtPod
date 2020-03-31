/*
 * Header file for the Song class
 * Dilya Anvarbekova and Teddy Hsieh
 */

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <iostream>
using namespace std;

class Song {
    private:
        string artist;
        string title;
        int size;

    public:
        Song();
        Song(string title);
        Song(string artist, string title, int size);

        /* FUNCTION - string getTitle
         *  returns the title of the song
         */
        string getTitle() const;

        /* FUNCTION - void setTitle
         *  sets the title of the song to a new one
         */
        void setTitle(string n);

        /* FUNCTION - string getArtist
         *  returns the artist of the song
         */
        string getArtist() const;

        /* FUNCTION - void setArtist
         *  sets the artist of the song to a new one
         */
        void setArtist(string n);

        /* FUNCTION - int getSize
         *  returns the size of the song
         */
        int getSize() const;

        /* FUNCTION - void setSize
         *  sets the size of the song to a new one
         */
        void setSize(int s);

        /* FUNCTION - void swap
         *  swaps the places of two songs
         *  - useful in sorting and shuffling
         */
        void swap(Song &s);

        /* FUNCTION - bool operator >
         *  compares the artist, then title, then size to sort in alphabetical
         *  order
         *  returns true if the song is after rhs alphabetically
         */
        bool operator >(Song const &rhs);

        /* FUNCTION - bool operator ==
         *  compares the artist, then title, then size
         *  returns true if all components of two songs are the same
         */
        bool operator ==(Song const &rhs);

        /* FUNCTION - bool operator <
         *  compares the artist, then title, then size to sort in reverse
         *  alphabetical order
         *  returns true if the song is before rhs alphabetically
         */
        bool operator <(Song const &rhs);

        ~Song();


};


#endif //UTPOD_SONG_H
