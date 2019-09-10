/*********************************************************************************
Author: Long Do
Date: 8/12/2017
Description: This is the definition file for Store class functions.
*********************************************************************************/

#include <string>
#include <vector>
#include <iostream>
#include "Store.hpp"



using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;



// This function is named addProduct. It will add a product to the inventory.
void Store::addProduct(Product* p)
{
	inventory.push_back(p);
}

// This function is named addMember. It will add a customer to the members.
void Store::addMember(Customer* c)
{
	members.push_back(c);
}

// This function is named getProductFromID. It will return pointer to
// product with matching ID. It will return NULL if no matching ID is found.
Product* Store::getProductFromID(string id)
{
	Product* searchResult = NULL;

	for (unsigned int count = 0; count < inventory.size(); count++)
	{
		if ((inventory[count])->getIdCode() == id)
		{
			searchResult = inventory[count];
		}
	}

	return searchResult;
}

// This function is named getMemberFromID. It will return pointer to
// customer with matching ID. It will returns NULL if no matching ID is found.
Customer* Store::getMemberFromID(string id)
{
	Customer* searchResult = NULL;

	for (unsigned int count = 0; count < members.size(); count++)
	{
		if ((members[count])->getAccountID() == id)
		{
			searchResult = members[count];
		}
	}

	return searchResult;
}

// This function is named productSearch. For every product whose title or
// description contains the search string, it will print out that
// product's title, ID code, price and description.
void Store::productSearch(string str)
{
	int searchTitle;
	int searchDescription;
	vector<int> mark;
	string searchTerm, tempTitle, tempDes;

	// Convert str to lowercase
	for (unsigned int count = 0; count < str.size(); count++)
	{
		searchTerm += tolower(str[count]);
	}


	// The search loop
	for (unsigned int count = 0; count < inventory.size(); count++)
	{
		// Convert Product's title to lowercase
		for (unsigned int index1 = 0; index1 < (inventory[count]->getTitle()).size(); index1++)
		{
			tempTitle += tolower((inventory[count]->getTitle())[index1]);
		}

		// Covert Product's description to lowercase
		for (unsigned int index2 = 0; index2 < ((inventory[count])->getDescription()).size(); index2++)
		{
			tempDes += tolower((inventory[count]->getDescription())[index2]);
		}

		// Perform the search
		searchTitle = tempTitle.find(searchTerm);
		searchDescription = tempDes.find(searchTerm);

		// When the search result is valid, get the bookmark
		if (searchTitle != -1 || searchDescription != -1)
		{
			mark.push_back(count);
		}

		// Clear temporary strings for the loop to repeat
		tempTitle.clear();
		tempDes.clear();
	}

	// Display the search results
	for (unsigned int count = 0; count < mark.size(); count++)
	{
		cout << endl;
		cout << inventory[mark[count]]->getTitle() << endl;
		cout << "ID Code: " << inventory[mark[count]]->getIdCode() << endl;
		cout << "Price: $" << inventory[mark[count]]->getPrice() << endl;
		cout << inventory[mark[count]]->getDescription() << endl;
		cout << endl;
	}
}

// This function is named addProductToMemberCart. If the product isn't
// found in the inventory, it will print "Product #[idCode goes here]
// not found." If the member isn't found in the members, it will print
// "Member #[accountID goes here] not found." If both are found and the
// product is still available, it will call the member's addProductToCart method.
// Otherwise it will print "Sorry, product #[idCode goes here] is currently
// out of stock." The same product can be added multiple times if the
// customer wants more than one of something.
void Store::addProductToMemberCart(string pID, string mID)
{
	Product* addProduct;
	Customer* addCustomer;
	int available;

	// Search for product
	addProduct = getProductFromID(pID);
	if (addProduct == NULL)
	{
		cout << endl;
		cout << "Product #" << pID << " not found." << endl;
	}

	// Search for customer
	addCustomer = getMemberFromID(mID);
	if (addCustomer == NULL)
	{
		cout << endl;
		cout << "Member #" << mID << " not found." << endl;
	}

	// When both product and customer are founded
	if (addProduct != NULL && addCustomer != NULL)
	{
		available = addProduct->getQuantityAvailable();

		// When the product is still available
		if (available > 0)
		{
			addCustomer->addProductToCart(pID);
		}

		// When the product is out of stock
		else
		{
			cout << endl;
			cout << "Sorry, product #" << pID
				<< " is currently out of stock." << endl;
		}
	}
}

// This function is named checkOutMember. If the member isn't found in
// the members, it will print "Member #[accountID goes here] not found."
// Otherwise, it will print out the title and price for each product in
// the cart and decreases the available quantity of that product by 1.
// If any product has already sold out, then on that line it should print
// 'Sorry, product #[idCode goes here], "[product name goes here]", is no
// longer available.' At the bottom it should print out the subtotal for
// the cart, the shipping cost ($0 for premium members, 7% of the cart
// cost for normal members), and the final total cost for the cart
// (subtotal plus shipping). If the cart is empty, it should just print
// "There are no items in the cart." When the calculations are complete,
// the member's cart should be emptied.
void Store::checkOutMember(string mID)
{
	vector<string> memberCart;
	vector<Product*> productCart;
	double cost = 0;
	double shipping;
	double total = 0;
	Customer* member;
	member = getMemberFromID(mID);

	// When the member cannot be founded
	if (member == NULL)
	{
		cout << endl;
		cout << "Member #" << mID << " not found." << endl;
	}
	// The member can be founded
	else
	{
		// If the member's cart is empty
		if ((member->getCart()).size() == 0)
		{
			cout << endl;
			cout << "There are no items in your cart." << endl;
		}

		// If the member's cart is not empty
		else
		{
			// Copy values from member's cart into memberCart temporary vector
			for (unsigned int count = 0; count < (member->getCart()).size(); count++)
			{
				memberCart.push_back((member->getCart())[count]);
			}

			// Get pointers to products
			for (unsigned int count = 0; count < memberCart.size(); count++)
			{
				productCart.push_back(getProductFromID(memberCart[count]));
			}

			// Display each product and calculate cost
			for (unsigned int index = 0; index < productCart.size(); index++)
			{
				// When the product is still available
				if (productCart[index]->getQuantityAvailable() != 0)
				{
					cout << endl;
					cout << productCart[index]->getTitle() << "  -  $"
						<< productCart[index]->getPrice() << endl;
					// Calculate product cost
					cost = cost + (productCart[index]->getPrice());
					// Decrease product's stock by 1
					productCart[index]->decreaseQuantity();
				}
				// When the product is no longer available
				else
				{
					cout << endl;
					cout << "Sorry, product #" << productCart[index]->getIdCode() << ", "
						<< productCart[index]->getTitle() << ", is no longer available.";
					cout << endl;
				}
			}

			// Determine the shipping cost
			// For premium members
			if (member->isPremiumMember() == true)
			{
				shipping = 0;
			}
			// For normal members
			else
			{
				shipping = cost * 0.07;
			}

			// Determine the total cost and display results
			total = cost + shipping;
			cout << endl;
			cout << "Subtotal: " << "$" << cost << endl;
			cout << "Shipping Cost: " << "$" << shipping << endl;
			cout << "Total: " << "$" << total << endl;

			// Clear the customer's cart after all calculations
			(member->getCart()).clear();
			memberCart.clear();
			productCart.clear();
		}
	}
}