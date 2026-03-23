#include "User.h"
#include <cstring>
#include<iostream>
#pragma warning(disable : 4996)

int User::idCounter = 0;

void User::free() {
	delete[] username;
	delete[] password;
	delete[] favorites;

	username = password = nullptr;
	favorites = nullptr;
}

void User::copyFrom(const User& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(username, other.username);

	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);

	balance = other.balance;
	userId = other.userId;
	cart = other.cart;

	favoritesCapacity = other.favoritesCapacity;
	favoritesSize = other.favoritesSize;
	favorites = new Product[favoritesCapacity];

	for (size_t i = 0; i < favoritesSize; i++)
	{
		favorites[i] = other.favorites[i];
	}
}

void User::resizeFavorites()
{
	favoritesCapacity *= 2;
	Product* temp = new Product[favoritesCapacity];

	for (size_t i = 0; i < favoritesSize; i++)
	{
		temp[i] = favorites[i];
	}

	delete[] favorites;
	favorites = temp;
}


User::User(const char* username, double balance)
 : balance(balance), userId(idCounter++), favoritesCapacity(2), favoritesSize(0)
{
	if (username != nullptr) {
		this->username = new char[strlen(username) + 1];
		strcpy(this->username, username);
	}
	else {
		this->username = new char[1];
		this->username[0] = '\0';
	}

	this->password = new char[1];
	this->password[0] = '\0';

	this->favorites = new Product[favoritesCapacity];
}

User::User() : balance(0), userId(idCounter++), favoritesCapacity(2), favoritesSize(0)
{
	username = new char[1];
	username[0] = '\0';

	password = new char[1];
	password[0] = '\0';

	favorites = new Product[favoritesCapacity];
}

User::User(const User& other)
{
	copyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

User::~User()
{
	free();
}

double User::getBalance() const
{
	return balance;
}

const Cart& User::getCart() const
{
	return cart;
}

void User::addToCart(const Product& product)
{
	cart.addProduct(product);
}

void User::removeFromCart(const Product& product)
{
	cart.removeProduct(product);
}
bool User::buy()
{
	if (this->balance >= cart.getTotal()) {

		this->balance -= cart.getTotal();
		cart.clear();
		return true;
	}
	
	return false;
}
