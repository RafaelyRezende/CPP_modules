#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called.\n";
    _type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called.\n";
}

Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment called.\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called.\n";
}

void    Cat::makeSound() const
{
    std::cout << "Miau\n";
}
