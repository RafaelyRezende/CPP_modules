#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const std::string& type);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
        Animal(const Animal& other);

    protected:
        std::string _type;
};

#endif