//Diego Rivera Lab08
#include "linkedlist.hpp"

LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

LinkedList::LinkedList(const LinkedList& other){
    first = nullptr;
    last = nullptr;
    size = 0;
    Node *temp = other.first;
    while (temp != nullptr){
        InsertLast(temp->value);
        temp = temp->next;
    }
}

LinkedList::~LinkedList() {
    for (int i = 0; i <size; ++i){
        DeleteFirst();
    }
}

ostream& operator<< (ostream& out, const LinkedList& LL) {
    Node* ptr = LL.first;
    while(ptr != nullptr){
        out << ptr->value << " ";
        ptr = ptr->next;
    }
    return out;
}

bool LinkedList::InsertFirst(int v){
    Node* temp= new Node;
    temp->value = v;
    temp->next = first;
    first = temp;
    size += 1;
    if (size == 1){
        last = temp;
    }
    return true;

}

bool LinkedList::InsertLast(int v) {
    Node* temp= new Node;
    temp->value=v;
    temp->next = nullptr;
    if (first == nullptr){
        last = temp;
        first = temp;
    }
    else{
        last->next=temp;
        last = temp;
    }
    size +=1;
    return true;
}

bool LinkedList::DeleteFirst() {
    bool check = true;
    if (first == nullptr) {
        check = false;
    }
    else {
        Node *temp = first;
        first = first->next;
        delete temp;
        size -= 1;
        if (first == nullptr) {
            last = nullptr;
        }
    }
    return check;
}
bool LinkedList::DeleteLast() {
    bool check = true;
    if (first == nullptr) {
        check = false;
    }
    else {
        Node *pretemp = last;
        Node *temp= first;
        for (int i =0; i <size-2; ++i){
            temp= temp->next;
        }
        temp->next = nullptr;
        delete pretemp;
        last = temp;
        size -= 1;

        if (size == 0) {
            first = nullptr;
        }

    }
    return check;
}

bool LinkedList::operator==(const LinkedList &other) const {
    if(this->size != other.size){
        return false;
    }
    else{
        Node *thistemp = first;
        Node *othertemp = other.first;
        for (int i = 0; i < size; ++i){
            if (thistemp->value != othertemp->value){
                return false;
            }
            thistemp = thistemp->next;
            othertemp = othertemp->next;

        }
    }
    return true;
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
    if (this == &other){
        return *this;
    }
    for (int i = 0; i <size; ++i){
        DeleteFirst();
    }
    Node *temp = other.first;
    while (temp != nullptr){
        InsertLast(temp->value);
        temp = temp->next;

    }
    return *this;
}