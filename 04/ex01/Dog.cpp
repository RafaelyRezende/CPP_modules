#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called.\n";
    _type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called.\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called.\n";
}

Dog&    Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called.\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Woof Woof\n";
}
