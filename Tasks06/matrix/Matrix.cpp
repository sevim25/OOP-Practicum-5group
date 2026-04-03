#include <iostream>
#include "Matrix.h"
#include <compare>

void Matrix::createMatrix()
{
	data = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		data[i] = new int[cols] {};
	}
}

void Matrix::free() {
	for (size_t i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
	data = nullptr;
}


void Matrix::copyFrom(const Matrix& other)
{
	rows = other.rows;
	cols = other.cols;
	createMatrix();

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}

Matrix::Matrix() : rows(2), cols(2) {
	createMatrix();
}

Matrix::Matrix(size_t size) : rows(size), cols(size) {
	createMatrix();
}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}

size_t Matrix::getSize() const {
	return rows;
}

int* Matrix::operator[](size_t i) {
	return data[i];
}

const int* Matrix::operator[](size_t i) const {
	return data[i];
}

int& Matrix::operator()(size_t i, size_t j)
{
	return data[i][j];
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (rows != other.rows) {
		return *this;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] += other.data[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (rows != other.rows) {
		return *this;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] -= other.data[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(int scalar)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] *= scalar;
		}
	}

	return *this;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	/*if (m1.cols != m2.rows) {
		return ;
	}*/

	size_t size = m1.getSize();
	Matrix result(size);

	for (size_t i = 0; i < size; i++) 
	{
		for (size_t j = 0; j < size; j++) 
		{
			for (size_t k = 0; k < size; k++)
			{
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	return result;
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix result(m1);
	result += m2;
	return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	Matrix result(m1);
	result -= m2;
	return result;
}

int getSum(const Matrix& m)
{
	int sum = 0;
	size_t size = m.getSize();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			sum += m[i][j];
		}
	}
	return sum;
}



std::strong_ordering operator<=>(const Matrix& m1, const Matrix& m2)
{
	int sumM1 = getSum(m1);
	int sumM2 = getSum(m2);

	return sumM1 <=> sumM2;
}

Matrix& Matrix::operator++() {
	Matrix ed(rows);
	
	for (size_t i = 0; i < rows; i++)
	{
		ed[i][i] = 1;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			data[i][j] += ed[i][j];
		}
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	for (size_t i = 0; i < m.getSize(); i++)
	{
		for (size_t j = 0;  j < m.getSize();  j++)
		{
			os << m[i][j] << " ";
		}
		os << '\n';
	}
	return os;
}

std::istream& operator>>(std::istream& is, Matrix& m)
{
	for (size_t i = 0; i < m.getSize(); i++)
	{
		for (size_t j = 0; j < m.getSize(); j++)
		{
			is >> m[i][j];
		}
	}
	return is;
}
