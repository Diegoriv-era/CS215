#include <iostream>
#include <sstream>
#include "playlist.h"
using namespace std;

int main( ) {
    PlayList a("P1", "file2.txt");
    cout << a;

    a.ChangeSongPosition("W219",2);
    a.ChangeSongPosition("SD567",5);
    a.ChangeSongPosition("JJ234",1);
    a.ChangeSongPosition("SD123",6);
    cout << endl << a << endl;
       
    a.PlayFirstSong();
    cout << endl << a;
    return 0;
}

