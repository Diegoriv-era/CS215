//Diego Rivera Lab10
#include "orderedset.hpp"


OrderedSet::OrderedSet() {
    first = nullptr;
    last = nullptr;
    size = 0;
}


OrderedSet::OrderedSet(const OrderedSet& other){
    first = nullptr;
    last = nullptr;
    size = 0;
    Node *temp = other.first;
    while (temp != nullptr){
        InsertLast(temp->value);
        temp = temp->next;
    }
}

OrderedSet::~OrderedSet() {
    for (int i = 0; i <size; ++i){
        DeleteFirst();
    }
}

bool OrderedSet::Insert(int v){
    Node *temp = first;
    if(temp == nullptr){
        InsertFirst(v);
        return true;
    }
    while(temp != nullptr) {
        if (temp->value == v) {
            return false;
        }
        if (temp->value > v) {
            if (temp->prev == nullptr) {
                InsertFirst(v);
                return true;
            }
            else {
                Node *new1 = new Node;
                new1->value = v;
                new1->next = temp;
                new1->prev = temp->prev;
                new1->prev->next = new1;
                temp->prev = new1;
                size++;
                return true;
            }
        }
        if (temp->next == nullptr) {
            InsertLast(v);
            return true;
        }
        temp = temp->next;
    }
}
ostream& operator<< (ostream& out, const OrderedSet& LL) {
    Node* ptr = LL.first;
    while(ptr != nullptr){
        out << ptr->value << " ";
        ptr = ptr->next;
    }
    return out;
}


bool OrderedSet::InsertFirst(int v){
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

bool OrderedSet::InsertLast(int v) {
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

bool OrderedSet::DeleteFirst() {
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
bool OrderedSet::DeleteLast() {
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

bool OrderedSet::operator==(const OrderedSet &other) const {
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

OrderedSet &OrderedSet::operator=(const OrderedSet &other) {
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

void OrderedSet::PrintBackwards(ostream &out) {
    Node* loop;
    loop = last;
    while(loop != NULL){
        out << loop->value << " ";
        loop = loop->prev;
    }
}
void OrderedSet::apply(void function(int& param)) {
    for (Node* n = last; n != NULL; n = n->prev) {
        function(n->value);
    }
}
OrderedSet OrderedSet::operator+(const OrderedSet& other) const{
    Node* temp = first;
    OrderedSet test;
    while(temp != nullptr){
        test.InsertLast(temp->value);
        temp = temp->next;
    }
    temp = other.first;
    while(temp != nullptr){

        test.Insert(temp->value);
        temp = temp->next;
    }
    return test;
}
void OrderedSet::clear() {
    int num = size;
    for (int i = 0; i < num; ++i){

        DeleteFirst();
    }
}
bool OrderedSet::exists(int v) {
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
bool OrderedSet::Delete(int v) {
    Node* temp = first;
    if(size == 0){
        return false;
    }
    while(temp!= nullptr){
        if (temp->value == v) {
            if (temp == first) {
                DeleteFirst();
                return true;
            }
            else if (temp == last){
                DeleteLast();
                return true;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                size--;
                return true;
            }
        }
        temp= temp->next;
    }
}
OrderedSet OrderedSet::operator*(const OrderedSet &other) const {
    Node* temp = first;
    Node* temp2 = other.first;
    OrderedSet test;
    while(temp != nullptr){
        while(temp2 != nullptr){
            if(temp->value == temp2->value){
                test.InsertLast(temp->value);
                break;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return test;
}