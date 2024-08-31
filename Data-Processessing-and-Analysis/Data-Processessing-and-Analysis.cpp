#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "ProductSale.h"
#include "Customer.h"

using namespace std;

int readTransactions(string inputFilePath)
{
    // Initialize class objects
    map<int, Customer> customers;
    vector<Customer> hvCustomers;
    vector<ProductSale> allSales;
    int lineNumber = 0;
    string formatError = "\nPlease verify all entries are formatted as follows:\n '123,123.45,2024-12-31'\n\n";

    // Open input csv file
    ifstream inputFile;
    inputFile.open(inputFilePath);
    string line = "";
    while (getline(inputFile, line))
    {
        lineNumber++;
        int customerID;
        double price;
        string date;
        string tempString = "";

        stringstream inputString(line);

        // Get the customerID by converting the text to an integer
        getline(inputString, tempString, ',');
        customerID = atoi(tempString.c_str());

        // Get the price customerID by converting the text to an integer
        tempString = "";
        getline(inputString, tempString, ',');
        price = atof(tempString.c_str());

        // Get the date string
        getline(inputString, date, ',');

        // Create a sale object and check if data is formatted correctly
        ProductSale sale(customerID, price, date);
        try
        {
            sale.checkFormat();
        }
        catch (std::invalid_argument& e)
        {
            cerr << e.what() << "at line " << lineNumber << "." << formatError << endl;
            return -1;
        }

        // If valid, add sale to allSales list
        allSales.push_back(sale);

        // Look for the current customer ID, if found, add to customers list
        auto id = customers.find(customerID);
        if (id != customers.end())
        {
            Customer& customer = customers.at(customerID);
            customer.CustomerSales.push_back(sale);
            // Update total and average price for current custoemr
            customer.TotalPrice += price;
            customer.AveragePrice = customer.TotalPrice / size(customer.CustomerSales);

            // Check if customer should be added to High-Value list
            if (customer.TotalPrice >= 500)
            {
                hvCustomers.push_back(customer);
            }
        }
        // Create a new customer and add to list otherwise
        else
        {
            vector<ProductSale> sales;
            sales.push_back(sale);
            Customer customer(customerID, sales, price, price);
            customers.insert_or_assign(customerID, customer);
            customer.TotalPrice = price;
            customer.AveragePrice = customer.TotalPrice / size(customer.CustomerSales);

            if (customer.TotalPrice >= 500)
            {
                hvCustomers.push_back(customer);
            }
        }

        line = "";
    }
    inputFile.close();

    // Display all unique customers and their information
    for (auto id : customers)
    {
        Customer customer = id.second;
        customer.display();
    }

    // Show all high-value customers
    cout << "High-Value Customers (Threshold $500):\n";
    for (auto hvCustomer : hvCustomers)
    {

        hvCustomer.displayValue();
    }

    // Add up all sale prices and display total value
    double inventoryValue = 0.00;
    for (auto sale : allSales)
    {
        inventoryValue += sale.Price;
    }
    cout << "Total Value of All Inventory Sold:\n" << inventoryValue << endl << endl;

    return 0;
}

int main(int argc, char* argv[])
{
    // Set your input filepath here
    string inputFilePath = "C:\\Your\\Input\\Filepath\\Here\\";
    ifstream infile(inputFilePath);
    // Check if given filepath is valid
    if (infile)
    {
        readTransactions(inputFilePath);
    }
    else
    {
        cout << "No input file found. Please verify that the input filepath is correct.\n";
    }

    return 0;
}

