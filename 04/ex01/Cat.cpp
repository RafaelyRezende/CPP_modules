#include "Cat.hpp"
#include "Brain.hpp"
#include <cstdlib>
#include <iostream>

Cat::Cat() : Animal()
{
    _type = "Cat";
    catBrain = new Brain();
    std::cout << "Cat constructor called.\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    catBrain = new Brain(*other.catBrain);
    _type = other._type;
    std::cout << "Copy Cat.\n";
}

Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Copy Cat assignment.\n";
    if (this != &other)
    {
        Animal::operator=(other);
        delete catBrain;
        catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

Cat::~Cat()
{
    delete catBrain;
    std::cout << "Cat destructor called.\n";
}

void    Cat::makeSound() const
{
    int rgn = std::rand() % MAX_IDEAS;
    std::cout << "Miau " + catBrain->getIdea(rgn) + " !" << std::endl;
}

Brain* Cat::getBrain() const
{
    return catBrain;
}
