#include "Animal.hpp"
#include <iostream>

Animal::Animal() {}

Animal::Animal(const std::string& type) : _type(type) {}

Animal::~Animal() {}

Animal::Animal(const Animal& other) : _type(other._type) {}

void    Animal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}
std::string Animal::getType() const
{
    return _type;
}