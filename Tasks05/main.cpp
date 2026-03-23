
#include <iostream>
#include "User.h"
#include "Cart.h"
#include "Product.h"

using std::cout;

int main()
{
	Product p1("Shoes", "Nike", 44, 99);
	Product p2("T-shirt", "Nike", 32, 30);
	User user("User", 100);


	user.addToCart(p1);
	user.addToCart(p2);

	cout << "Total products price: ";
	cout << user.getCart().getTotal();

	cout << '\n';

	cout << "User's balance: ";
	cout << user.getBalance();

	cout << '\n';

	if (user.buy()) {
		cout << "The payment is successful\n";
	}
	else {
		cout << "Not enough money\n";
	}
}
