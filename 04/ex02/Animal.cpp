#include "Animal.hpp"
#include <iostream>

// Contructor
Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

// Copy Assignment
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called." << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

// NOTE: makeSound() is pure virtual (= 0 in Animal.hpp) and has no
// definition here on purpose — Animal is abstract and cannot be
// instantiated; concrete classes provide their own implementation.

std::string Animal::getType() const
{
    return _type;
}
