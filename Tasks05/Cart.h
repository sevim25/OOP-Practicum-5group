#pragma once
#include "Product.h"

class Cart
{
private:
	Product* products;
	size_t size = 0;
	size_t capacity = 0;

	int id;
	static int idCounter;

	void resizeCart();

	void free();
	void copyFrom(const Cart& other);

public:
	Cart();
	Cart(const Cart& other);
	Cart& operator=(const Cart& other);
	~Cart();

	size_t getSize() const;
	int getId()const;
	double getTotal() const;


	void addProduct(const Product& product);
	void removeProduct(const Product& product);
	void clear();
};

