#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor call" << std::endl;
}

Fixed::Fixed(Fixed& a)
{
	std::cout << "Copy assigment call" << std::endl;
	_numValue = a._numValue;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor call" << std::endl;
}

Fixed& operator=(const Fixed& other)

int	Fixed::getRawBits()
{
	std::cout << "getRawBits function call" << std::endl;
	return (1);
}
