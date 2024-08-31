#include "ProductSale.h"
#include <stdexcept>

ProductSale::ProductSale(int customerID, double price, string date)
{
    CustomerID = customerID;
    Price = price;
    Date = date;
}

// Shows sale information
void ProductSale::display()
{
    cout << "   Customer ID: " << CustomerID << endl;
    cout << "         Price: " << Price << endl;
    cout << "          Date: " << Date << endl;
    cout << endl;
}

// Checks if data read from input file is formatted correctly, throws an error otherwise
void ProductSale::checkFormat()
{

    if (CustomerID == NULL)
    {   
        throw  std::invalid_argument("CustomerID formatted incorrectly ");
    }
    if (Price == NULL)
    {
        throw  std::invalid_argument("Price formatted incorrectly ");
    }
    if (Date == "")
    {
        throw  std::invalid_argument("Date formatted incorrectly ");
    }

}