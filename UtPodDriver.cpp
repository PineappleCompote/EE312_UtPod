/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Song.h"
#include "UtPod.h"

#define MAX_MEMORY 512
#define SUCCESS 0

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


	//testing random songs
	srand(time(0));
	int SONG_MEM = rand()% MAX_MEMORY + 1;
	const int n2 = rand()%SONG_MEM + 1;
	Song randList[MAX_MEMORY];
	string artist;
	string title;
	const int MAX_LEN = 10;
	for(int i = 0; i < n2; i++){
		int alen = rand() % MAX_LEN;
		int tlen = rand() % MAX_LEN;

		artist = "";
		for(int j = 0; j < alen; j++)	
			artist += rand() % ('z' - '0' + 1) + '0';
		for(int j = alen; j < MAX_LEN; j++)
			artist += " ";

		title = "";
		for(int j = 0; j < tlen; j++)
			title +=  rand() % ('z' - '0' + 1) + '0';
		for(int j = tlen; j < MAX_LEN; j++)
			title += " ";
		int size = rand() % 30  + 1;

		
		Song s(artist, title, size);
		randList[i] = s;
	}

	//adding songs	
	UtPod randT(SONG_MEM);
	int remaining = SONG_MEM; //should track how much memory left in song
	int count = 0;
	bool added[MAX_MEMORY];
	for(int i = 0; i < n2; i++)
		added[i] = false;
	cout << "total mem: " << randT.getTotalMemory() << endl;
	cout << "Adding songs......................." << endl;
	for(int i = 0; i < n2; i++){
		//expensive mem check
		int memleft = randT.getRemainingMemory();
		if(memleft != remaining){
			cout << "getRemainingMemory() failed.\n";
			cout << "Function count: " << memleft;
			cout << "real value: " << remaining<< endl;
			break;
		}

		if(remaining < randList[i].getSize()){
			cout << randList[i].getTitle() <<  " SHOULD FAIL.  need: "
				<< + randList[i].getSize() << "  has: " << remaining << endl;
			if(remaining == 0){
				cout << "Memory full...exiting....\n";
				break;
			}
		}

		if(randT.addSong(randList[i]) == SUCCESS){
			cout << randList[i].getTitle() << " added successfully\n";
			remaining -= randList[i].getSize();
			count++;
			added[i] = true;	
		}

		else
			cout << randList[i].getTitle() << " FAILED TO ADD\n";
	}

	cout << endl;
	cout << "songs added: " << count << endl;
	randT.showSongList();
	
	cout << endl << "Removing Songs.......................\n";
	int numRemoved = 0;
	int randRemove = rand() % count + 1;
	for(int i = 0; i < randRemove; i++){
		if(rand() % 4){
			int removed;
			do{
				removed = rand() % n2;
			}
			while(!added[removed]);
			cout << "Removing " << randList[removed].getTitle() << endl;
			randT.removeSong(randList[removed]);
			numRemoved ++;
			added[removed] = false;
		}

		else{
			cout << "SHOULD FAIL to remove " << "GARBAGE\n"; 
			Song garbage("GARBAGE", "GARBAGE", 20);
			if(randT.removeSong(garbage) == SUCCESS)
				cout << "something went wrong";
		}
	}

	count -= numRemoved;
	cout << endl;
	cout << "songs removed: " << numRemoved << endl;

	randT.showSongList();

	cout << endl;
	cout << "Sorting............................\n";
	randT.sortSongList();
	randT.showSongList();


	cout << endl;
	cout << "Shuffling ..............................\n";
	randT.shuffle();
	randT.showSongList();

	cout << endl;
	cout << "Resorted................................\n";
	randT.sortSongList();
	randT.showSongList();

	cout << endl;
	
}
