//
// Created by Diego Rivera on 5/2/22.
//
#include "playlist.h"
#include <sstream>
#include <fstream>

PlayList::PlayList(){
    first = nullptr;
    last = nullptr;
    size = 0;
    name = "";
}
PlayList::PlayList(string playname){
    first = nullptr;
    last = nullptr;
    size = 0;
    name = playname;
}
PlayList::PlayList(string playname,string filename){
    first = nullptr;
    last = nullptr;
    size = 0;
    name = playname;

    string id, suml, name, artist;
    int sonlen = 0;

    ifstream data;
    data.open(filename);
    if(!data.is_open()){
        cout << "Could not open " << filename;
    }
    while(!data.eof()){
        getline(data,id);
        getline(data, name);
        getline(data,artist);
        data >> sonlen;
        data.ignore();
        Node *temp = new Node;
        temp->uniqueID = id;
        temp->songName = name;
        temp->artistName = artist;
        temp->songLength = sonlen;
        InsertNodeLast(temp);
    }


}
PlayList::~PlayList(){
    int num = size;
    for (int i = 0; i < num; ++i){
        DeleteFirst();
    }
}

bool PlayList::InsertNodeLast(Node *myNewNode) {
    if(size == 0){
        first = myNewNode;
        last = myNewNode;
        myNewNode->nextNodePtr= nullptr; //changed first to mynewnode
        size += 1;
    }
    else {
        if(myNewNode == nullptr){
            cout << "its null" << endl;
            return false;
        }
        last->nextNodePtr = myNewNode;
        last = myNewNode;
        myNewNode->nextNodePtr= nullptr;
        size++;
    }
    return true;
}

bool PlayList::InsertNodeFirst(Node *myNewNode) {
    if(size == 0){
        first = myNewNode;
        last = myNewNode;
        first->nextNodePtr= nullptr;
        size =1;
    }
    else {
        myNewNode->nextNodePtr = first;
        first = myNewNode;
        size++;
    }
    return true;
}

bool PlayList::DeleteFirst() {
    if(size == 0){
        return false;
    }
    else{
        Node* temp= first;
        first = first->nextNodePtr;
        delete temp;
        size--;
        if(first == nullptr){
            last = nullptr;
        }
    }
    return true;
}
ostream& operator<< (ostream& out, const PlayList& LL){
    Node *temp = LL.first;
    Node *count = LL.first;
    int total = 0;
    for (int i = 0; i < LL.size; ++i){
        total += count->songLength;
        count = count->nextNodePtr;
    }
    out << "***Playlist " << LL.name <<" contains " << LL.size <<" songs with a total playtime of " << total <<" seconds***" << endl;
    while(temp!= nullptr) {
        out << '"' << temp->songName << '"' << " by " << temp->artistName << " is "
            << temp->songLength << " seconds long (ID " << temp->uniqueID << ")." << endl;
        temp = temp->nextNodePtr;
    }
    return out;
}
PlayList& PlayList::operator=(const PlayList &other) {
    int num = size;
    if (this == &other){
        return *this;
    }
    for (int i = 0; i <num; ++i){
        DeleteFirst();
    }

    Node *curr = other.first;
    while (curr != nullptr){
        Node *temp = new Node;
        temp->uniqueID = curr->uniqueID;
        temp->songName = curr->songName;
        temp->artistName = curr->artistName;
        temp->songLength = curr->songLength;
        InsertNodeFirst(temp);
        curr = curr->nextNodePtr;
    }
    return *this;
}
bool PlayList::IsSongPresent(string uniqueID) {
    Node *temp = first;
    while(temp!= nullptr){
        if(temp->uniqueID == uniqueID){
            return true;
        }
        temp = temp->nextNodePtr;
    }
    return false;
}
bool PlayList::AddSong(string uniqueID, string songName, string artistName, int songLength) {
    Node *toinsert = new Node;
    toinsert->uniqueID = uniqueID;
    toinsert->songName = songName;
    toinsert->artistName = artistName;
    toinsert->songLength = songLength;
    toinsert->nextNodePtr = nullptr;
    if(IsSongPresent(uniqueID)){
        return false;
    }
    else{
        InsertNodeLast(toinsert);
        return true;
    }

}

bool PlayList::RemoveSong(string uniqueID) {
    Node *temp = first;
    Node *ptr1 = first;
    if (IsSongPresent(uniqueID)){
        while(temp!= nullptr) {
            if (temp->uniqueID == uniqueID) {
                if (temp == first) {
                    DeleteFirst();
                    return true;
                }
                else {
                    ptr1->nextNodePtr = temp->nextNodePtr;
                    if (ptr1->nextNodePtr == nullptr) {
                        last = ptr1;
                    }
                    delete temp;
                    size--;
                    return true;
                }
            }
            ptr1 = temp;
            temp = temp->nextNodePtr;
        }
    }
    else{
        cout << "Song with unique ID " << uniqueID <<" does not exist." << endl;
        return false;
    }
}

bool PlayList::PlayFirstSong() {
    if(size == 0){
        cout << "Sorry, play list is empty!" << endl;
        return false;
    }
    else{
        cout << "Playing \"" << first->songName << "\" by " << first->artistName << endl;
        DeleteFirst();
        return true;
    }
}

PlayList PlayList::operator+(const PlayList &other) {
    PlayList out;
    out.name = name + other.name;
    Node *temp = first;
    Node *temp2 = other.first;
    while(temp!= nullptr){
        out.AddSong(temp->uniqueID, temp->songName, temp->artistName, temp->songLength);
        temp = temp->nextNodePtr;
    }
    while(temp2 != nullptr){
        out.AddSong(temp2->uniqueID, temp2->songName, temp2->artistName, temp2->songLength);
        temp2 = temp2->nextNodePtr;
    }
    return out;
}

void PlayList::Shuffle() {
    PlayList firstl;
    PlayList second;
    Node *temp = this->first;
    int firsthalf = size/2;
    int thesize = size;
    for(int i= 0; i < thesize; ++i){
        if(i < firsthalf) {
            Node *copy = new Node;
            copy->uniqueID = temp->uniqueID;
            copy->songName = temp->songName;
            copy->artistName = temp->artistName;
            copy->songLength = temp->songLength;
            firstl.InsertNodeLast(copy);
        }
        else{
            Node *copy = new Node;
            copy->uniqueID = temp->uniqueID;
            copy->songName = temp->songName;
            copy->artistName = temp->artistName;
            copy->songLength = temp->songLength;
            second.InsertNodeFirst(copy);
        }
        temp = temp->nextNodePtr;
    }
    *this = firstl + second;
}

bool PlayList::ChangeSongPosition(string uniqueID, int newPosition) {
    Node *temp = first;
    Node *copy = new Node;
    Node *ptr = temp;
    for (int i = 0; i < size; ++i){
        if (temp->uniqueID == uniqueID) {
            copy->uniqueID = temp->uniqueID;
            copy->songLength = temp->songLength;
            copy->artistName = temp->artistName;
            copy->songName = temp->songName;
            break;
        }
        temp = temp->nextNodePtr;
    }
    RemoveSong(uniqueID);
    temp = first;
    if(newPosition == 1){
        InsertNodeFirst(copy);
    }
    else if(newPosition == size+1){
        InsertNodeLast(copy);
    }
    else{
        for (int i = 0; i < size; ++i){
            if(i + 1 == newPosition){
                break;
            }
            ptr = temp; //when loop breaks ptr pointing to the node that precedes temp
            temp = temp->nextNodePtr; //when loop breaks temp should be the node that will be pushed back
        }
        ptr->nextNodePtr = copy;
        copy->nextNodePtr = temp;
        size++;
    }
}