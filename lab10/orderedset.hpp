// Diego Rivera Lab10
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

class OrderedSet {

    public:
        OrderedSet(); // assigns first, last and size to null and 0.
        OrderedSet(const OrderedSet& other); //copies the values of the set in the parameters. a deep copy
        ~OrderedSet(); // deletes the whole set.

        void apply(void function(int& param)); //takes a function as a parameter and does it to the whole set.
        bool Insert(int v); //Inserts the value keeping the same order. Calls InsertFirst and InsertLast from within.
        bool Delete(int v); // Deletes the element in the set that matches value in parameter.
        int Size() const { return size; } // gives size of set

        void PrintBackwards(ostream& out); //prints backwards
        void clear(); //deletes the whole set.
        bool exists(int v); //checks if the value exists in the set

        OrderedSet& operator=(const OrderedSet& other); //deletes old set and assigns other set to this set.
        OrderedSet operator+(const OrderedSet& other) const; // merges both ordered list in order. does not have any duplicates
        OrderedSet operator*(const OrderedSet& other) const; // merges both ordered sets but only if they both exist in both lists
        bool operator==(const OrderedSet& other) const; // checks if all values are equal.
        friend ostream& operator<< (ostream& out, const OrderedSet& LL); // prints the list in a ostream;\

    private:
        Node* first;
        Node* last;
        int size;

        bool InsertFirst(int v);
        bool InsertLast(int v);
        bool DeleteFirst();
        bool DeleteLast(); 
};
