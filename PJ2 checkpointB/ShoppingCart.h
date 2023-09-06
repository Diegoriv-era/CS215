//
// Created by diego on 3/19/2022.
//
#ifndef PROJECT02_B_SHOPPINGCART_H
#define PROJECT02_B_SHOPPINGCART_H

#endif //PROJECT02_B_SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart{

public:
    ShoppingCart();
    ShoppingCart(string name, string date);

    string GetCustomerName();
    string GetDate();

    void AddItem(ItemToPurchase P);

    bool IsItemInCart(string name, int& num);

    void RemoveItem(string name);

    void ModifyItem(ItemToPurchase P);

    int GetNumItemsInCart();

    int GetCostOfCart();

    void PrintTotal();

    void PrintDescriptions();

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};