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
    Fixed(const int value); // Constructor that converts int to fixed point value
    Fixed(const float value); // Constructor that converts float to fixed point value
    Fixed(const Fixed &fixed); // Copy constructor
    Fixed& operator=(const Fixed &other); // Copy assignment operator

    int		toInt(void) const;
    float	toFloat(void) const;
    int		getRawBits(void) const;
    void	setRawBits(int const raw);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
