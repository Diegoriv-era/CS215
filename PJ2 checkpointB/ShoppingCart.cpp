//
// Created by diego on 3/19/2022.
//

#include <iostream>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}
string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase P) {
    int quantity = P.GetQuantity();
    if (quantity != 0)
    {
        cartItems.push_back(P);
    }
}

bool ShoppingCart::IsItemInCart(string name, int &num) {
    bool test = false;
    for (int i = 0; i < cartItems.size(); ++i){

        //cout << "TEST :" << name << endl << "TEST IN CART :" << cartItems.at(i).GetName() << endl;

        if (name == cartItems.at(i).GetName())
        {
            test = true;
            num = i;
        }
    }
    return test;
}

void ShoppingCart::RemoveItem(string name) {

    int num = 0;
    if (IsItemInCart(name, num))
    {
        cartItems.erase(cartItems.begin()+num);
    }
    else
    {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
    cout << endl;

}


void ShoppingCart::ModifyItem(ItemToPurchase P)
    {
        int num = 0;
        bool check = IsItemInCart(P.GetName(), num);
        if (!check) {
            cout << "Item not found in cart. Nothing modified." << endl << endl;
        }
        else {
            if (P.GetDescription() != "none") {

                cartItems.at(num).SetDescription(P.GetDescription());
            }
            if (P.GetPrice() != 0) {
                cartItems.at(num).SetPrice(P.GetPrice());
            }
            if (P.GetQuantity() != 0) {
                cartItems.at(num).SetQuantity(P.GetQuantity());
            }
        }
    }
    int ShoppingCart::GetNumItemsInCart() {
        int num = 0;
        for (int i = 0; i < cartItems.size(); ++i) {
            num += cartItems.at(i).GetQuantity();
        }
        return num;
    }
    int ShoppingCart::GetCostOfCart() {
        int tot = 0;
        int price = 0;
        int quantity = 0;

        for (int i = 0; i < cartItems.size(); ++i) {
            quantity = cartItems.at(i).GetQuantity();
            price = cartItems.at(i).GetPrice();
            tot += quantity * price;

        }
        return tot;
    }

    void ShoppingCart::PrintTotal() {
        string name;
        int num = 0;
        name = GetCustomerName();
        cout << name << "'s Shopping Cart - " << GetDate() << endl;
        cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

        for (int i = 0; i < cartItems.size(); ++i) {
            num += cartItems.at(i).PrintItemCost();
        }
        if (GetNumItemsInCart() == 0)
        {
            cout << "SHOPPING CART IS EMPTY" << endl;
        }
        cout << endl << "Total: $" << num << endl << endl;
    }
    void ShoppingCart::PrintDescriptions() {
        string name;
        name = GetCustomerName();
        cout << name << "'s Shopping Cart - " << GetDate() << endl << endl;
        cout << "Item Descriptions" << endl;
        for (int i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemDescription();
        }
        cout << endl;
    }
