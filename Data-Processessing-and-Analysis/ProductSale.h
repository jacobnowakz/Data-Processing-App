#pragma once
#include <iostream>
#include <string>

using namespace std;

class ProductSale
{
public:
    ProductSale(int customerID, double price, string date);
    int CustomerID;
    double Price;
    string Date;

    void display();
    void checkFormat();
};
