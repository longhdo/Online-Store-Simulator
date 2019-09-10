#include <iostream>
#include <string>
#include "Store.hpp"


int main()
{
	using std::vector;
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;


	Product item1("02719", "Red Computer Fan", "A computer fan with red LED.", 30.00, 10);
	Product item2("03621", "Asus Motherboard", "A fancy gaming motherboard from Asus with red LED.", 250.00, 5);
	Product item3("35778", "Caselabs Computer Case", "A fancy computer case from Caselabs with blue and red decorations.", 300.00, 10);
	Product item4("90009", "Giant Robot", "A giant robot with blue lazer guns to defend against communist invasions.", 10000.00, 1);
	Product item5("09127", "Mini Nuclear Power Supply", "A mini nuclear power supply with blue and red glowing fuel cells.", 100000.00, 1);
	Product item6("88888", "Garden of Eden", "A fancy garden with red roses and blue angels.", 666.00, 0);


	Customer member1("Emmanuel Kant", "093871", false);
	Customer member2("Karl Max", "000666", false);
	Customer member3("Long Do", "254927", true);
	Customer member4("George Washington", "070476", true);
	Customer member5("Manlee Do", "050688", true);

	Store happy;

	happy.addProduct(&item1);
	happy.addProduct(&item2);
	happy.addProduct(&item3);
	happy.addProduct(&item4);
	happy.addProduct(&item5);
	happy.addProduct(&item6);

	happy.addMember(&member1);
	happy.addMember(&member2);
	happy.addMember(&member3);
	happy.addMember(&member4);
	happy.addMember(&member5);

	cout << endl;
	cout << "The search term is: Red." << endl;
	happy.productSearch("Red");
	cout << endl;

	cout << "Test addProductToMemberCart when no product is found.";
	happy.addProductToMemberCart("11111", "000666");
	cout << endl;

	cout << "Test addProductToMemberCart when no member is found.";
	happy.addProductToMemberCart("90009", "111111");
	cout << endl;

	cout << "Test addProductToMemberCart when the product is out of stock.";
	happy.addProductToMemberCart("88888", "000666");
	cout << endl;

	cout << "Test checkOutMember function, when member is invalid.";
	happy.checkOutMember("111111");
	cout << endl;

	cout << "Test checkOutMember function, when member's cart is empty.";
	happy.checkOutMember("070476");
	cout << endl;

	happy.addProductToMemberCart("02719", "254927");
	happy.addProductToMemberCart("02719", "254927");
	happy.addProductToMemberCart("02719", "254927");
	happy.addProductToMemberCart("02719", "254927");
	happy.addProductToMemberCart("02719", "254927");
	happy.addProductToMemberCart("03621", "254927");
	happy.addProductToMemberCart("90009", "254927");
	happy.addProductToMemberCart("90009", "254927");
	happy.addProductToMemberCart("88888", "254927");
	happy.addProductToMemberCart("09127", "254927");
	happy.addProductToMemberCart("09127", "254927");
	happy.addProductToMemberCart("35778", "254927");

	cout << endl;
	cout << "Test checkOutMember function, when member Long Do (premium) makes purchases.";
	cout << endl;
	happy.checkOutMember("254927");
	cout << endl;

	happy.addProductToMemberCart("02719", "093871");
	happy.addProductToMemberCart("02719", "093871");
	happy.addProductToMemberCart("02719", "093871");
	happy.addProductToMemberCart("02719", "093871");
	happy.addProductToMemberCart("02719", "093871");
	happy.addProductToMemberCart("03621", "093871");
	happy.addProductToMemberCart("90009", "093871");
	happy.addProductToMemberCart("90009", "093871");
	happy.addProductToMemberCart("09127", "093871");
	happy.addProductToMemberCart("09127", "093871");
	happy.addProductToMemberCart("35778", "093871");

	cout << endl;
	cout << "Test checkOutMember function, when member Emmanuel Kant (non-premium) makes purchases.";
	cout << endl;
	happy.checkOutMember("093871");
	cout << endl;

	return 0;
}