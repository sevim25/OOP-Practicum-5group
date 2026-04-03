#include "GeometricVector.h"

void GeometricVector::free()
{
	delete[]data;
	data = nullptr;
}

void GeometricVector::copyFrom(const GeometricVector& other)
{
	size = other.size;
	if (other.data != nullptr) {
		data = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
}

void GeometricVector::resize(int newSize)
{
	int* temp = new int[newSize] {0};
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[]data;
	size = newSize;
	data = temp;
}

GeometricVector::GeometricVector() : size(3)
{
	data = new int[size];
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}

GeometricVector::GeometricVector(int* data, size_t size) : size(size)
{
	if (data != nullptr) {
		this->data = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			this->data[i] = data[i];
		}
	}
	else {
		this->data = new int[size] {};
	}
}

GeometricVector::GeometricVector(size_t size) : size(size), data(new int[size]{})
{
}

GeometricVector::GeometricVector(const GeometricVector& other)
{
	copyFrom(other);
}

GeometricVector& GeometricVector::operator=(const GeometricVector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

GeometricVector::~GeometricVector()
{
	free();
}

size_t GeometricVector::getSize() const
{
	return size;
}

int GeometricVector::getCoord(size_t index) const
{
	if (index >= size) {
		return 0;
	}
	return data[index];
}


GeometricVector& GeometricVector::operator*(int scalar)
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] *= scalar;
	}

	return *this;
}

GeometricVector& GeometricVector::operator+=(const GeometricVector& v) {
	for (size_t i = 0; i < size; i++)
	{
		data[i] += v.getCoord(i);
	}

	return *this;
}

GeometricVector& GeometricVector::operator-=(const GeometricVector& v) {
	for (size_t i = 0; i < size; i++)
	{
		data[i] -= v.data[i];
	}
	return *this;
}

double operator%(const GeometricVector& v1, const GeometricVector& v2)
{
	double res = 0;
	size_t minSize = std::min(v1.size, v2.size);

	for (size_t i = 0; i < minSize; i++)
	{
		res += v1.data[i] * v2.data[i];
	}

	return res;
}

GeometricVector operator+(const GeometricVector& v1, const GeometricVector& v2)
{
	GeometricVector result(v1);
	result += v2;
	return result;
}

GeometricVector operator-(const GeometricVector& v1, const GeometricVector& v2) {
	GeometricVector result(v1);
	result -= v2;
	return result;
}

int& GeometricVector::operator[](size_t index) {
	return data[index];
}

GeometricVector operator^(const GeometricVector& v1, const GeometricVector& v2)
{
	if (v1.size > 3 || v2.size > 3) {
		return GeometricVector();
	}

	GeometricVector result(3);
	
	result[0] = v1.getCoord(1) * v2.getCoord(2) - v1.getCoord(2) * v2.getCoord(1);
	result[1] = v1.getCoord(2) * v2.getCoord(0) - v1.getCoord(0) * v2.getCoord(2);
	result[2] = v1.getCoord(0) * v2.getCoord(1) - v1.getCoord(1) * v2.getCoord(0);

	return result;
}

double GeometricVector::getLen() const
{
	double sumSquares = 0;
	for (size_t i = 0; i < size; i++)
	{
		sumSquares += getCoord(i) * getCoord(i);
	}

	return std::sqrt(sumSquares);
}

double getCos(const GeometricVector& v1, const GeometricVector& v2)
{
	return (v1 % v2) / (v1.getLen() * v2.getLen());
}

std::ostream& operator<<(std::ostream& os, const GeometricVector& v)
{
	os << "( ";
	for (size_t i = 0; i < v.size; i++)
	{
		os << v.data[i];
		os << " ";
	}
	os << ")";

	return os;
}

std::istream& operator>>(std::istream& is, GeometricVector& v)
{
	for (size_t i = 0; i < v.size; i++)
	{
		is >> v.data[i];
	}
	return is;
}

