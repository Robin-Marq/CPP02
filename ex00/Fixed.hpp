#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed); // Copy constructor
    Fixed& operator=(const Fixed &other); // Copy assignment operator
    
    void setRawBits(int const raw);
    int getRawBits(void) const;
};

#endif