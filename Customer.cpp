/********************************************************************************
Author: Long Do
Date: 8/12/2017
Description: This is the definition file of Customer class functions.
********************************************************************************/

#include <string>
#include "Customer.hpp"

using std::string;
using std::vector;



// This is the constructor which takes as parameters three values with
// which to initialize the Customer's name, account ID, and whether
// the customer is a premium member.
Customer::Customer(string na, string id, bool pm)
{
	name = na;
	accountID = id;
	premiumMember = pm;
}

// These are get methods which will return the value of the
// corresponding data member.
string Customer::getAccountID()
{
	return accountID;
}

vector<string> Customer::getCart()
{
	return cart;
}

// This function is named isPremiumMember. It will return whether
// the customer is a premium member or not.
bool Customer::isPremiumMember()
{
	return premiumMember;
}

// This function is named addProductToCart. It will add the product
// ID code to the Customer's cart.
void Customer::addProductToCart(string id)
{
	cart.push_back(id);
}

// This function is named emptyCart. It will empty the Customer's cart.
void Customer::emptyCart()
{
	cart.clear();
}