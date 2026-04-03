#pragma once
#include <iostream>

class GeometricProgression {
private:
	double a1 = 1;
	double q = 1;

public:
	GeometricProgression();
	GeometricProgression(double a1, double q);

	double operator[](size_t index) const;
	double operator()(size_t n) const;

	friend GeometricProgression operator+(const GeometricProgression& lhs, const GeometricProgression& rhs);
	friend GeometricProgression operator*(const GeometricProgression& lhs, const GeometricProgression& rhs);

	friend std::ostream& operator<<(std::ostream& os, const GeometricProgression& p);
	friend std::istream& operator>>(std::istream& is, GeometricProgression& p);
};
