#include "Brain.hpp"
#include <iostream>
#include <fstream>

Brain::Brain()
{
    std::cout << "I got " << MAX_IDEAS << " idea!" << std::endl;
    std::ifstream ifs;

    ifs.open("random_words.txt", std::ifstream::in);
    if (ifs.fail())
    {
        std::cout << "Failed to open the file." << std::endl;
        for (int i = 0; i < MAX_IDEAS; i++)
            _ideas[i] = "None";
    }
    else
    {
        std::string line;
        int i = 0;

        while (ifs.good() && i < MAX_IDEAS)
        {
            getline(ifs, line);
            _ideas[i] = line;
            i++;
        }
    }
    ifs.close();
}

Brain::~Brain()
{
    std::cout << "Fade to black" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Rob ideas" << std::endl;
    for (int i = 0; i < MAX_IDEAS; i++)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assigned." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < MAX_IDEAS; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& new_idea)
{
    if (index >= 0 && index < MAX_IDEAS)
        _ideas[index] = new_idea;
}

const std::string& Brain::getIdea(int index) const
{
    return _ideas[index];
}
