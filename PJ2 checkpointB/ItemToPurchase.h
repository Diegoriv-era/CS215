#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    void SetName(string name);
    string GetName();

    void SetPrice(int price);
    int GetPrice();

    void SetQuantity(int num);
    int GetQuantity();

    void SetDescription(string desc);
    string GetDescription();

    void PrintItemDescription();

    int PrintItemCost();

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;



};


#endif