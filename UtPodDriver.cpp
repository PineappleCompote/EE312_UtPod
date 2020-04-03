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
    UtPod t;

    cout << "total mem: " << t.getTotalMemory() << endl;
    cout << "remaining mem: " << t.getRemainingMemory() << endl;

	const int n = 8;
	Song list[n]= {
			Song("abc", "1", 34),
			Song("bac", "2", 23),
			Song("a", "23", 4),
			Song("yyy", "11", 4),
			Song("yyy", "11", 7),
			Song("yyy", "11", 4),
			Song("e", "great song mate!", 22),
			Song("HUGE", "BIG", 511)	};

	for(int i = 0; i < n; i++)
		t.addSong(list[i]); 
	cout << "Unsorted list: \n";
	t.showSongList();

	cout << "\nSorted list: \n";
	t.sortSongList();
	t.showSongList();

	cout << "\nShuffled list: \n";
	t.shuffle();
	t.showSongList();
/*
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;


    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
*/

}
