#include "Customer.h"

Customer::Customer
(
    int id,
    vector<ProductSale> customerSales,
    double totalPrice,
    double averagePrice
)
{
    ID = id;
    CustomerSales = customerSales;
    TotalPrice = totalPrice;
    AveragePrice = averagePrice;
}

// Shows customer information
void Customer::display()
{
    cout << "CustomerID: " << ID;
    cout << ", Total: " << TotalPrice;
    cout << ", Average: " << AveragePrice << endl;
}

// Shows total customer purchase value
void Customer::displayValue()
{
    cout << "CustomerID: " << ID;
    cout << ", Total: " << TotalPrice << endl;
    cout << endl;
}