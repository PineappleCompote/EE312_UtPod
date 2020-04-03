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

	UtPod::UtPod(const UtPod& old)
	{
		songs = old.songs;
		if(old.memSize > MAX_MEMORY || old.memSize <= 0)
			memSize = MAX_MEMORY;
		else 
			memSize = old.memSize;
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
		Song arr[numSongs];
		SongNode* temp = songs;
	
		//make temporary list to sort easier
		for(int i = 0; i < numSongs; i++){
			arr[i] = temp->s;
			temp = temp->next;
		}

		for(int i = 0; i < numSongs-1; i++){
			int  min = i;
			for(int j = i+1; j < numSongs; j++){
				if(arr[j] < arr[min])
					min = j;	
			}	

			if(min != i)
				arr[i].swap(arr[min]);	
		}

		//now copy sorted list to UtPod
		temp = songs;
		for(int i = 0; i < numSongs; i++){
			temp->s = arr[i];
			temp = temp->next;
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

	UtPod& UtPod::operator =(UtPod const &p)
	{
		if(this != &p){
			clearMemory();
			songs = p.songs;
			memSize = p.memSize;
		}
		return *this;
	}

	UtPod::~UtPod()
	{
		clearMemory();
	}




