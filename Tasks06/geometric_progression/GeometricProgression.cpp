#include "GeometricProgression.h"
#include <cmath>

GeometricProgression::GeometricProgression() : a1(1), q(1)
{
}

GeometricProgression::GeometricProgression(double a1, double q) : a1(a1), q(q)
{
}


GeometricProgression operator+(const GeometricProgression& lhs, const GeometricProgression& rhs)
{
	return { lhs.a1 + rhs.a1, lhs.q + rhs.q };
}

GeometricProgression operator*(const GeometricProgression& lhs, const GeometricProgression& rhs)
{
	return { lhs.a1 * rhs.a1, lhs.q * rhs.q };
}

double GeometricProgression::operator[](size_t index) const {
	return a1 * (std::pow(q, index));
}

double GeometricProgression::operator()(size_t n) const
{
	if (q == 1) {
		return n * a1;
	}

	double sum = a1 * (std::pow(q, n) - 1) / (q - 1);
	return sum;
}

std::ostream& operator<<(std::ostream& os, const GeometricProgression& p)
{
	os << p.a1 << " " << p.q;
	return os;
}

std::istream& operator>>(std::istream& is, GeometricProgression& p)
{
	is >> p.a1 >> p.q;
	return is;
}
