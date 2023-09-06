#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

#include "ShoppingCart.h"
//#include "cmake-build-debug/ShoppingCart.h"

void PrintMenu(ShoppingCart obj)
{
    string input, name, desc, name2;
    char c;
    int price, quantity, index;
    bool check;
    ItemToPurchase item1;

    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;

    cin >> c;
    while (c != 'q') {

        if (c != 'a' && c != 'd' && c != 'c' && c != 'i' && c != 'o') {
            cout << "Choose an option:" << endl;
            cin >> c;
            continue;
        }

        else if (c == 'o')
        {
            cout << "OUTPUT SHOPPING CART" << endl;
            obj.PrintTotal();
        }
        else if (c == 'i')
        {
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            obj.PrintDescriptions();
        }
        else if (c == 'a')
        {
            cout << "ADD ITEM TO CART" << endl;

            //cin >> name;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            getline(cin, name);
            item1.SetName(name);


            cout << "Enter the item description:" << endl;
            getline(cin, desc);
            item1.SetDescription(desc);

            cout << "Enter the item price:" << endl;
            cin >> price;
            item1.SetPrice(price);

            cout << "Enter the item quantity:" << endl;
            cin >> quantity;
            cout << endl;
            item1.SetQuantity(quantity);

            obj.AddItem(item1);
        }
        else if (c == 'd')
        {
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, name2);
            getline(cin, name2);
            //cout << endl;
            obj.RemoveItem(name2);

        }
        else if (c == 'c')
        {
            ItemToPurchase test;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            getline(cin, name);
            test.SetName(name);

            cout << "Enter the new quantity:" << endl;
            cin >> quantity;

            test.SetQuantity(quantity);

            //item1.SetQuantity(quantity);
            obj.ModifyItem(test);
        }
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option:" << endl;
        cin >> c;
    }
}



int main() {
    int num;
    string name, date;

    cout << "Enter customer's name:" << endl;
    getline(cin, name);

    cout << "Enter today's date:" << endl;
    getline(cin, date);

    cout <<endl << "Customer name: " << name << endl << "Today's date: " << date << endl;
    ShoppingCart obj1(name,date);
    cout << endl;
    PrintMenu(obj1);

   return 0;
}