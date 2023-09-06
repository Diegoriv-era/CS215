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
    if (temp == nullptr){
        return false;
    }
    temp->value = v;
    temp->next = first;
    temp->prev= nullptr;
    if(size != 0){
        first->prev = temp;
    }
    first = temp;
    if(size ==0){
        last = first;
    }
    size += 1;
    return true;

}

bool LinkedList::InsertLast(int v) {
    Node* temp= new Node;
    temp->value=v;
    temp->prev = last;
    temp->next = nullptr;
    if (size == 0){
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
    if (size ==0) {
        return false;
    }
    if(size ==1){
        delete first;
        first= nullptr;
        last = nullptr;
        size =0;
        return true;
    }

    Node *temp = first;
    first = first->next;
    delete temp;
    first->prev= nullptr;
    size -= 1;
    return true;


}
bool LinkedList::DeleteLast() {
    if(size == 0){
        return false;
    }
    if(size ==1){
        delete last;
        first = last = nullptr;

        size = 0;
        return true;
    }
    Node * temp = last;
    last = last -> prev;
    last -> next = nullptr;
    delete temp;
    size -= 1;
    return true;

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

void LinkedList::PrintBackwards(ostream &out) {
    Node* loop;
    loop = last;
    while(loop != NULL){
        out << loop->value << " ";
        loop = loop->prev;
    }
}
void LinkedList::apply(void function(int& param)) {
    for (Node* n = last; n != NULL; n = n->prev) {
        function(n->value);
    }
}
LinkedList LinkedList::operator+(const LinkedList& other) const{
    Node* temp = first;
    LinkedList test;


    while(temp != nullptr){
        test.InsertLast(temp->value);
        temp = temp->next;
    }
    temp = other.first;
    while(temp != nullptr){
        test.InsertLast(temp->value);
        temp = temp->next;
    }



    return test;


}
void LinkedList::clear() {
    int num = size;
    for (int i = 0; i < num; ++i){

        DeleteFirst();
    }
}
bool LinkedList::exists(int v) {
    bool check = false;
    Node* temp = first;
    while(temp!= nullptr){
        if (temp->value == v){
            check = true;
        }
        temp= temp->next;
    }

    return check;
}