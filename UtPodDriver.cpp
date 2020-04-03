/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t(256);

    cout << "total mem: " << t.getTotalMemory() << endl;
    cout << "remaining mem: " << t.getRemainingMemory() << endl;

//    const int n = 8;
//    Song list[n]= {
//            Song("abc", "1", 34),
//            Song("bac", "2", 23),
//            Song("a", "23", 4),
//            Song("yyy", "11", 4),
//            Song("yyy", "11", 7),
//            Song("yyy", "11", 4),
//            Song("e", "great song mate!", 22),
//            Song("HUGE", "BIG", 511)  };
//
//    for(int i = 0; i < n; i++)
//        t.addSong(list[i]);
//    cout << "Unsorted list: \n";
//    t.showSongList();
//
//    cout << "\nSorted list: \n";
//    t.sortSongList();
//    t.showSongList();
//
//    cout << "\nShuffled list: \n";
//    t.shuffle();
//    t.showSongList();


    const int n = 9;
    Song list1[n] = {
            Song("The Beatles", "Hey Jude1", 25),
            Song("The Beatles", "Hey Jude2", 25),
            Song("The Beatles", "Yellow Submarine", 25),
            Song("AC/DC", "Highway to Hell", 25),
            Song("Led Zeppelin", "Stairway to Heaven", 12),
            Song("Pink Floyd", "Wish You Were Here", 35),
            Song("Pink FLoyd", "Wish You Were Here", 30),
            Song("Nirvana", "Come As You Are", 15),
            Song("AC/DC", "Back In Black", 40)
    };

    for(int i = 0; i < n; i++){
        t.addSong(list1[i]);
    }

    cout << "Total number of songs: " << t.getNumSongs() << "\n" << endl;

    cout << "Unsorted list:" << endl;
    t.showSongList();

    cout << endl;

    t.sortSongList();
    cout << "Sorted List (by artist):" << endl;
    t.showSongList();
    cout << endl;

    t.removeSong(list1[1]);
    cout << "Removed Hey Jude2: " << endl;
    t.showSongList();
    cout << endl;
    cout << "Number of songs: " << t.getNumSongs() << endl;
    cout << "Total memory: " << t.getTotalMemory() << endl;
    cout << "Remaining memory: " << t.getRemainingMemory() << endl;

    cout << "Trying to add a song over the memory limit..." << endl;
    cout << "Number of songs before: " << t.getNumSongs() << endl;
    Song newSong("Aerosmith", "Dream On", 50);
    t.addSong(newSong);
    cout << "Number of songs after: " << t.getNumSongs() << endl << endl;


    t.shuffle();
    cout << "Shuffled songs:" << endl;
    t.showSongList();
    cout << endl;

    t.shuffle();
    cout << "Shuffle again:" << endl;
    t.showSongList();
    cout << endl;

    t.clearMemory();
    cout << "Memory cleared..." << endl;
    cout << "Remaining memory: " << t.getRemainingMemory() << endl;
    cout << "Number of songs: " << t.getNumSongs() << endl;

    t.shuffle();
    cout << "Shuffled empty UtPod" << endl;
    t.showSongList();
    cout << endl;

    cout << "Removing song not in UtPod..." << endl;
    t.removeSong(newSong);

    t.addSong(newSong);
    cout << "Showing added song: " << endl;
    t.showSongList();
    cout << endl;

    t.shuffle();
    t.showSongList();
    cout << endl;


    cout << "New UtPod created..." << endl;

    UtPod t1;

    Song s1("Artist1", "Title1", 50);
    Song s2("Artist2", "Title2", 50);
    Song s3("Artist3", "Title3", 400);
    Song s4("Artist4", "Title4", 50);

    cout << "UtPod t1 total memory: " << t1.getTotalMemory() << endl;
    cout << "UtPod t1 remaining memory: " << t1.getRemainingMemory() << endl;

    t1.addSong(s1);
    cout << "Adding s1 with " << s1.getSize() << "MB" << endl;
    t1.showSongList();
    cout << "UtPod t1 remaining memory: " << t1.getRemainingMemory() << endl;
    cout << endl;

    t1.addSong(s2);
    cout << "Adding s2 with " << s2.getSize() << "MB" << endl;
    t1.showSongList();
    cout << "UtPod t1 remaining memory: " << t1.getRemainingMemory() << endl;
    cout << endl;

    t1.addSong(s3);
    cout << "Adding s3 with " << s3.getSize() << "MB" << endl;
    t1.showSongList();
    cout << "UtPod t1 remaining memory: " << t1.getRemainingMemory() << endl;
    cout << endl;

    t1.addSong(s4);
    cout << "Adding s4 with " << s4.getSize() << "MB" << endl;
    t1.showSongList();
    cout << "UtPod t1 remaining memory: " << t1.getRemainingMemory() << endl;
    cout << endl;


}
