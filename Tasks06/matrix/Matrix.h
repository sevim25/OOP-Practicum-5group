#pragma once
#include <iostream>
#include <compare>

class Matrix
{
	size_t rows = 0; //size
	size_t cols = 0;
	int** data = nullptr;

	void createMatrix();
	void free();
	void copyFrom(const Matrix& other);

public:
	Matrix();
	explicit Matrix(size_t size);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	size_t getSize() const;
	int* operator[](size_t i);
	const int* operator[](size_t i) const;
	int& operator()(size_t i, size_t j);
	//int getCoord(size_t i, size_t j) const;

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(int scalar);
	//Matrix& operator*=(const Matrix& other);
	Matrix& operator++();

};

Matrix operator*(const Matrix& m1, const Matrix& m2);
Matrix operator+(const Matrix& m1, const Matrix& m2);
Matrix operator-(const Matrix& m1, const Matrix& m2);

int getSum(const Matrix& m);
// comparing by the sum of their elements
std::strong_ordering operator<=>(const Matrix& m1, const Matrix& m2);

std::ostream& operator<<(std::ostream& os, const Matrix& m);
std::istream& operator>>(std::istream& is, Matrix& m);
