//Diego Rivera Lab08
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {

    public:
        LinkedList(); // constructor initializes a size 0 linked list pointing first and last pointers to Null
        LinkedList(const LinkedList& other); // constructor that copies the linked list in the parameter. deletes old list and copies the new values, not the address.
        ~LinkedList(); //destructor calls the DeleteFirst function within a loop to delete each value one by one.

        bool InsertFirst(int v);//this member function returns true after inserting a node to the beginning of the linked list
        bool InsertLast(int v); //this member function returns true after inserting a node to the end of the linked list
        bool DeleteFirst();//this member function returns true after deleting the first node of the linked list
        bool DeleteLast();//this member function returns true after deleting the last node of the linked list

        int Size() const { return size; } //returns size of the list

        LinkedList& operator=(const LinkedList& other); //if they are not the same then the list is deleted one by one and then the values and size of 'other' are set.
        bool operator==(const LinkedList& other) const;// returns true if the size and all the values in the linked list are the same
        friend ostream& operator<< (ostream& out, const LinkedList& LL);  // << overloaded operator function. outputs into a string stream to test the code.

    private:
        Node* first;
        Node* last;
        int size;
};
