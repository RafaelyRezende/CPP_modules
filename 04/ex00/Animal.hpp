#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

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