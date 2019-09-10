/**********************************************************************************
Author: Long Do
Date: 8/12/2017
Description: This is the definition file for Product class functions.
**********************************************************************************/


#include <string>
#include "Product.hpp"

using std::string;


// This is the constructor which takes as parameters five values with which
// to initialize the Product's idCode, title, description, price,
// and quantity available.
Product::Product(string id, string t, string des, double p, int qa)
{
	idCode = id;
	title = t;
	description = des;
	price = p;
	quantityAvailable = qa;
}

// These are get methods which will return the value of the
// corresponding data member.
string Product::getIdCode()
{
	return idCode;
}

string Product::getTitle()
{
	return title;
}

string Product::getDescription()
{
	return description;
}

double Product::getPrice()
{
	return price;
}

int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

// This function is named decreaseQuantity. It will decreases the
// quantity available by one.
void Product::decreaseQuantity()
{
	quantityAvailable = quantityAvailable - 1;
}