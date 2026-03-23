#include "Product.h"
#include <cstring>
#pragma warning(disable : 4996)

int Product::count = 0;

void Product::free()
{
	delete[] name;
	name = nullptr;

	delete[] producer;
	producer = nullptr;
}

void Product::copyFrom(const Product& other)
{
	if (other.name != nullptr) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	else {
		name = new char[1];
		name[0] = '\0';
	}

	if (other.producer != nullptr) {
		producer = new char[strlen(other.producer) + 1];
		strcpy(producer, other.producer);
	}
	else {
		producer = new char[1];
		producer[0] = '\0';
	}

	size = other.size;
	price = other.price;
	id = other.id;
}

Product::Product() {
	this->id = count++;
}

Product::Product(const Product& other)
{
	copyFrom(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Product::~Product()
{
	free();
}

Product::Product(const char* name, const char* producer, size_t size, double price)
{
	setName(name);
	setProducer(producer);
	setSize(size);
	setPrice(price);

	this->id = count++;
}

const char* Product::getName() const
{
	return name;
}

const char* Product::getProducer() const
{
	return producer;
}

size_t Product::getSize() const
{
	return size;
}

double Product::getPrice() const
{
	return price;
}

int Product::getId() const
{
	return id;
}

void Product::setName(const char* name)
{
	delete[] this->name;
	if (name == nullptr) {
		this->name = new char[1];
		this->name[0] = '\0';
	}
	else {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Product::setProducer(const char* producer)
{
	delete[] this->producer;
	if (producer == nullptr) {
		this->producer = new char[1];
		this->producer[0] = '\0';
	}
	else {
		this->producer = new char[strlen(producer) + 1];
		strcpy(this->producer, producer);
	}
}

void Product::setSize(size_t size)
{
	this->size = size;
}

void Product::setPrice(double price)
{
	if (price > 0) {
		this->price = price;
	}
}