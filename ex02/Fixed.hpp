#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &fixed); // Copy constructor

	Fixed operator + (const Fixed &other) const; // Addition
    Fixed operator - (const Fixed &other) const; // Subtraction
    Fixed operator * (const Fixed &other) const; // Multiplication
    Fixed operator / (const Fixed &other) const; // Division

	Fixed &operator=(const Fixed &other); // Copy assignment operator
	Fixed &operator ++ (void); // Pre-increment
    Fixed operator ++ (int); // Post-increment
    Fixed &operator -- (void); // Pre-decrement
    Fixed operator -- (int); // Post-decrement

    bool operator < (const Fixed &other) const;
    bool operator > (const Fixed &other) const;
    void operator << (int const shift);
    void operator >> (int const shift);
    bool operator == (const Fixed &other) const;
    bool operator != (const Fixed &other) const;
    bool operator >= (const Fixed &other) const;
    bool operator <= (const Fixed &other) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

	int		toInt(void) const;
    float	toFloat(void) const;
    int		getRawBits(void) const;
    void	setRawBits(int const raw);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
