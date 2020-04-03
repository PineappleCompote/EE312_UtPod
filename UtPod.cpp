/*
 * UtPod.cpp
 * Teddy Hsieh and Dilya Anvarbekova
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UtPod.h" 

using namespace std;

	UtPod::UtPod()
	{
		songs = NULL;
		memSize = MAX_MEMORY;
	}

	UtPod::UtPod(int size)
	{
		songs = NULL;
		if(size > MAX_MEMORY || size <= 0)
			memSize = MAX_MEMORY;
		else
			memSize = size;
	}

	int UtPod::addSong(Song const &s)
	{
		if(s.getSize() >  getRemainingMemory())
			return NO_MEMORY;
		
		SongNode* newSongN = new SongNode;
		newSongN->s = s;
		newSongN->next = NULL;
	
		SongNode* curr = this->songs;
		//empty case
		if(curr == NULL)
			songs = newSongN;
		else{
			//set curr to last songnode
			while(curr->next != NULL)
	            curr = curr->next;
			curr->next = newSongN;
		}

		return SUCCESS;					
	}

	int UtPod::removeSong(Song const &s)
	{
		SongNode* currN = this->songs;
		//empty case
		if(currN == NULL)
			return NOT_FOUND;

		SongNode* prevN = NULL;
		SongNode* nextN = currN->next;
		while(currN != NULL){
			//song found, return sucess
			if(currN->s == s){
				if(prevN != NULL)
					prevN->next = currN->next;
				else{
					songs = currN->next; //remove head
				}
					
				delete currN;
				return SUCCESS;
			}
			
			prevN = currN;
			currN = currN->next; 
		}

		//song not in list
		return NOT_FOUND; 
	}

	int UtPod::getNumSongs()
	{
		int count = 0;
		SongNode* curr = this->songs;
		while(curr!= NULL){
			count++;
			curr = curr->next;
		}

		cout << "numSongs: " << count << endl; //debug
		return count;
	}

	void UtPod::shuffle()
	{
		int numSongs = getNumSongs();
		//Fisher-Yates shuffle
		Song arr[numSongs];
		SongNode* temp = songs;
		for(int i = 0; i < numSongs; i++){
			arr[i] = temp->s;
			temp = temp->next;
		}
		//generates random permutation of songs
		srand(time(0));
		for(int i = 0; i <= numSongs - 2; i++){
			int j = rand() % (numSongs-i) + i;
			arr[i].swap(arr[j]);
		}

		//puts songs into linked list
		temp = songs;
		for(int i = 0; i < numSongs; i++){
			temp->s = arr[i];
			temp = temp->next;
		}
	}

	void UtPod::showSongList()
	{
		SongNode* curr = this->songs;
		while(curr != NULL){
			cout << curr->s.getTitle() << ", " << curr->s.getArtist() << ", " << curr->s.getSize() << endl;
 
			curr = curr->next;
		}
	}

	void UtPod::sortSongList()
	{
		int numSongs = getNumSongs();
		SongNode* iN = songs;
		SongNode* jN; 	

		for(int i = 1; i < numSongs; i++){
			SongNode* min = iN;
			jN = iN->next;
			for(int j = i+1; j < numSongs; j++){
				if(jN->s < min->s)
					min = jN;	
				jN = jN->next;
			}

			if(min != iN)
				iN->s.swap(min->s);	
			
			iN = iN->next;
		}
	}

	void UtPod::clearMemory()
	{
		SongNode* temp;
		while(songs != NULL){
			temp = songs->next;
			delete songs;
			songs = temp;
		}
	}

	int UtPod::getTotalMemory()
	{
		return memSize;
	}

	int UtPod::getRemainingMemory()
	{
		int remaining = memSize;
		SongNode* curr = this->songs;
		while(curr != NULL){
			remaining = remaining - curr->s.getSize();
			curr  = curr->next;
		}

		return remaining;	
	}

	UtPod::~UtPod()
	{
		cout << "deleting UtPod...\n";

		clearMemory();
	}




