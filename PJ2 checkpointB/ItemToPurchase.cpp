#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
{
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    itemDescription = description;
}
void ItemToPurchase::SetName(string name) {
    itemName = name;
}
string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}
int ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int num) {
    itemQuantity = num;
}
int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string desc) {
    itemDescription = desc;
}
string ItemToPurchase::GetDescription() {
    return itemDescription;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;

}

int ItemToPurchase::PrintItemCost() {
    int total = 0;
    total = itemQuantity * itemPrice;
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << total << endl;
    return total;
}