#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor called.\n";
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called.\n";
}

WrongCat&    WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment called.\n";
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called.\n";
}

void    WrongCat::makeSound() const
{
    std::cout << "Uaim\n";
}
