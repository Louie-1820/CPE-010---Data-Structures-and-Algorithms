#include <iostream>
using namespace std;

double Item1, Item2, Item3;
double total, payment, change;
int main(){
    cout << "Task 2 (Cashiering System)" << endl;
    cout << "Enter the price of Item 1:" << endl;
    cin >> Item1;
    cout << "Enter the price of Item 2:" << endl;
    cin >> Item2;
    cout << "Enter the price of Item 3:" << endl;
    cin >> Item3;
    
    total = Item1 + Item2 + Item3;
    cout << "Total Price: " << total << endl;

    cout << "Enter amount to pay: ";
    cin >>  payment;

    change = payment - total; 

    cout << "======================" << endl;
    cout << "  OFFICIAL RECEIPT" << endl;
    cout << "======================" << endl;
    cout << "Price of Item 1: " << Item1 << " Php "<< endl;
    cout << "Price of Item 2: " << Item2 << " Php " << endl;
    cout << "Price of Item 3: " << Item3 << " Php " << endl;
    cout << "======================" << endl;
    cout << "Total Price: " << total << " Php " << endl;
    cout << "Payment: " << payment << " Php " << endl;
    cout << "Change: " << change << " Php " << endl; 
    cout << "======================";

    return 0;
}