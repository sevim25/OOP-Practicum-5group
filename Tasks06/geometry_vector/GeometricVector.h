#pragma once
#include <iostream>
class GeometricVector {
private:
	int* data = nullptr;
	size_t size = 0;

	void free();
	void copyFrom(const GeometricVector& other);
	void resize(int newSize);
	
	int getCoord(size_t index) const;

public:
	GeometricVector();
	GeometricVector(int* data, size_t size);
	GeometricVector(size_t size);
	GeometricVector(const GeometricVector& other);
	GeometricVector& operator=(const GeometricVector& other);
	~GeometricVector();

	size_t getSize() const; 
	double getLen() const;

	int& operator[](size_t index);

	GeometricVector& operator*(int scalar);

	GeometricVector& operator+=(const GeometricVector& v);
	GeometricVector& operator-=(const GeometricVector& v);

	friend double operator%(const GeometricVector& v1, const GeometricVector& v2); //scalar product
	friend GeometricVector operator^(const GeometricVector& v1, const GeometricVector& v2);//vector product

	friend std::ostream& operator<<(std::ostream& os, const GeometricVector& v);
	friend std::istream& operator>>(std::istream& is, GeometricVector& v);
};

GeometricVector operator+(const GeometricVector& v1, const GeometricVector& v2);
GeometricVector operator-(const GeometricVector& v1, const GeometricVector& v2);
double getCos(const GeometricVector& v1, const GeometricVector& v2);