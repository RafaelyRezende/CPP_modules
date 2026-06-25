#include "WrongAnimal.hpp"
#include <iostream>

// Contructor
WrongAnimal::WrongAnimal() : _type("")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Copy Assignment
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called." << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Some generic wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}
