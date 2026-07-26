#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
    _type = "Dog";
    dogBrain = new Brain();
    std::cout << "Dog spawned.\n";
}

Dog::~Dog()
{
    delete dogBrain;
    std::cout << "Dog destructor called.\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called.\n";
    dogBrain = new Brain(*other.dogBrain);
    _type = other._type;
}

Dog&    Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called.\n";
    if (this != &other)
    {
        Animal::operator=(other); // Delegates copy assignment to base class. Modify the dog specific members below.
        delete dogBrain;
        dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Woof Woof\n";
}

Brain* Dog::getBrain() const
{
    return dogBrain;
}
