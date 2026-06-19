#pragma once

#include <iostream>

class Fixed
{
private:
	int					_numValue;
	static const int	_fracBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(Fixed& a);
	Fixed& operator=(const Fixed& other)
	{
		if (this != &other)
		{
			this->_numValue = other._numValue;
		}
		return *this;
	}

	int getRawBits();
};
