#include "Cart.h"
#include "Product.h"
#include <cstring>
#pragma warning(disable : 4996)

int Cart::idCounter = 0;

void Cart::free() {
	delete[] products;
	products = nullptr;
}

void Cart::copyFrom(const Cart& other)
{
	capacity = other.capacity;
	size = other.size;
	id = other.id;

	products = new Product[capacity];

	for (size_t i = 0; i < size; i++)
	{
		products[i] = other.products[i];
	}
}

void Cart::resizeCart()
{
	capacity *= 2;
	Product* temp = new Product[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = products[i];
	}

	delete[]products;
	products = temp;
}

Cart::Cart() : size(0), capacity(2), id(idCounter++) {

	products = new Product[capacity];
}

Cart::Cart(const Cart& other)
{
	copyFrom(other);
}

Cart& Cart::operator=(const Cart& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Cart::~Cart()
{
	free();
}

double Cart::getTotal() const
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += products[i].getPrice();
	}
	return sum;
}

void Cart::addProduct(const Product& product)
{
	if (size == capacity) {
		resizeCart();
	}
	
	products[size++] = product;
}

void Cart::removeProduct(const Product& product)
{
	for (size_t i = 0; i < size; i++)
	{
		if (products[i].getId() == product.getId())
		{
			products[i] = products[size - 1];
			size--;

			return;
		}
	}
}

size_t Cart::getSize() const {
	return size;
}

void Cart::clear()
{
	this->size = 0;
}