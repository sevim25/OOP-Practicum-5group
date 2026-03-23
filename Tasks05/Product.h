#pragma once
class Product
{
private:
	char* name = nullptr;
	char* producer = nullptr;
	size_t size = 0;
	double price = 0;

	int id;
	static int count;

	void free();
	void copyFrom(const Product& other);

public:
	Product();
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	Product(const char* name, const char* producer, size_t size, double price);

	const char* getName() const;
	const char* getProducer() const;
	size_t getSize() const;
	double getPrice() const;
	int getId() const;

	void setName(const char* name);
	void setProducer(const char* producer);
	void setSize(size_t size);
	void setPrice(double price);

};

