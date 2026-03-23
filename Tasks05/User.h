#pragma once
#include "Cart.h"

class User
{
	Cart cart;
	char* username = nullptr;
	char* password = nullptr;
	double balance = 0;

	Product* favorites = nullptr;
	size_t favoritesSize = 0;
	size_t favoritesCapacity = 0;

	int userId;
	static int idCounter;

	void resizeFavorites();

	void free();
	void copyFrom(const User& other);

public:
	User(const char* username, double balance);

	User();
	User(const User& other);
	User& operator=(const User& other);
	~User();

	double getBalance()const;
	const Cart& getCart() const;

	void addToCart(const Product& product);
	void removeFromCart(const Product& product);
	bool buy();

};

