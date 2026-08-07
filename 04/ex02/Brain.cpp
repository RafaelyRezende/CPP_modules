#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < MAX_IDEAS; i++)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < MAX_IDEAS; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < MAX_IDEAS)
        _ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) const
{
    static const std::string empty;

    if (index < 0 || index >= MAX_IDEAS)
        return empty;
    return _ideas[index];
}
