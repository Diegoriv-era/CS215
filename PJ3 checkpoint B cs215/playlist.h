//
// Created by Diego Rivera on 5/9/22.
//

#ifndef PJ3_CHECKPOINT_B_CS215_PLAYLIST_H
#define PJ3_CHECKPOINT_B_CS215_PLAYLIST_H

#endif //PJ3_CHECKPOINT_B_CS215_PLAYLIST_H
#include <string>
#include <iostream>

using namespace std;

struct Node {
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    Node* nextNodePtr;

};

class PlayList{
public:
    PlayList();//Default constructor
    PlayList(string playname);
    PlayList(string filename, string playname); //Parameterized constructor that reads data members of song from a file and builds the PlayList
    ~PlayList(); //Deletes all nodes of the linked list

    bool InsertNodeLast(Node *myNewNode); //Inserts myNewNode at the end of the linked list
    bool InsertNodeFirst(Node *myNewNode); //Inserts myNewNode at the start of the linked list
    bool DeleteFirst(); //Deletes the first node of the linked list
    int Size() const { return size; }
    friend ostream& operator<< (ostream& out, const PlayList& LL); //Prints the linked list
    PlayList& operator=(const PlayList& other); //Overload the assignment operator such that the current PlayList is reverse of the other PlayLis
    bool IsSongPresent(string uniqueID);
    bool AddSong(string uniqueID, string songName, string artistName, int songLength); //Adds song to the end of the list, if the song (based off the uniqueId) is not already present
    bool RemoveSong(string uniqueID);
    bool PlayFirstSong(); //"Plays" first song if list is not empty and then deletes it from the PlayList. Otherwise, gives a message indicating list is empty.
    PlayList operator+(const PlayList& other);
    void Shuffle();
    bool ChangeSongPosition(string uniqueID, int newPosition);


private:
    Node* first;
    Node* last;
    int size;
    string name;


};