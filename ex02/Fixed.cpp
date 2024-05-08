#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &fixed)
{
	operator=(fixed);
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		_value = other._value;
	}
	return (*this);
}

Fixed Fixed::operator + (const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_value + other._value);
	return (result);
}

Fixed Fixed::operator - (const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_value - other._value);
	return (result);
}

Fixed Fixed::operator * (const Fixed &other) const
{
	Fixed result;
	result.setRawBits((_value * other._value) >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator / (const Fixed &other) const
{
	Fixed result;
	result.setRawBits((_value << _fractionalBits) / other._value);
	return (result);
}

void Fixed::operator << (int const shift)
{
	_value <<= shift;
}

void Fixed::operator >> (int const shift)
{
	_value >>= shift;
}

bool Fixed::operator > (const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator < (const Fixed &other) const
{
	return (_value < other._value);
}

bool Fixed::operator >= (const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator <= (const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator == (const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator != (const Fixed &other) const
{
	return (_value != other._value);
}


Fixed &Fixed::operator ++ (void)
{
	_value++;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator -- (void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}