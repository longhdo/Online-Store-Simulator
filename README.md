# Online Store Simulator

This is a (rather primitive) online store simulator written in C++. It will have 3 classes: Product, Customer and Store.

Here are descriptions of methods for the 3 classes:

**Product**

A Product object represents a product with an ID code, title, description, price and quantity available.

- constructor: takes as parameters five values with which to initialize the Product's idCode, title, description, price, and quantity available
- get methods: return the value of the corresponding data member
- decreaseQuantity: decreases the quantity available by one

**Customer**

A Customer object represents a customer with a name and account ID. Customers must be members of the Store to make a purchase. Premium members get free shipping.

- constructor: takes as parameters three values with which to initialize the Customer's name, account ID, and whether the customer is a premium member
- get methods: return the value of the corresponding data member
- isPremiumMember: returns whether the customer is a premium member
- addProductToCart: adds the product ID code to the Customer's cart
- emptyCart: empties the Customer's cart

**Store**

A Store object represents a store, which has some number of products in its inventory and some number of customers as members.

- addProduct: adds a product to the inventory
- addMember: adds a customer to the members
- getProductFromID: returns pointer to product with matching ID. Returns NULL if no matching ID is found.
- getMemberFromID: returns pointer to customer with matching ID. Returns NULL if no matching ID is found.
- productSearch: for every product whose title or description contains the search string, prints out that product's title, ID code, price and description. The first letter of the search string should be case-insensitive, i.e. a search for "wood" should match Products that have "Wood" in their title or description, and a search for "Wood" should match Products that have "wood" in their title or description.
- addProductToMemberCart: if the product isn't found in the inventory, print "Product #[idCode goes here] not found". If the member isn't found in the members, print "Member #[accountID goes here] not found". If both are found and the product is still available, calls the member's addProductToCart method. Otherwise it prints "Sorry, product #[idCode goes here] is currently out of stock". The same product can be added multiple times if the customer wants more than one of something.
- checkOutMember: if the member isn't found in the members, print "Member #[accountID goes here] not found". Otherwise prints out the title and price for each product in the cart and decreases the available quantity of that product by 1. If any product has already sold out, then on that line it should print 'Sorry, product #[idCode goes here], "[product name goes here]", is no longer available'. At the bottom it should print out the subtotal for the cart, the shipping cost ($0 for premium members, 7% of the cart cost for normal members), and the final total cost for the cart (subtotal plus shipping). If the cart is empty, it should just print "There are no items in the cart". When the calculations are complete, the member's cart should be emptied.
