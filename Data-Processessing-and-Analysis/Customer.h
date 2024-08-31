#pragma once
#include <vector>
#include "ProductSale.h"

using namespace std;

class Customer
{
public:
    Customer
    (
        int id,
        vector<ProductSale> customerSales,
        double totalPrice,
        double averagePrice
    );
    void display();
    void displayValue();

    int ID;
    vector<ProductSale> CustomerSales;
    double TotalPrice;
    double AveragePrice;

};