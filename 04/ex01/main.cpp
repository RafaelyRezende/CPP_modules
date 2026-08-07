#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    /* ============================================================
       SUBJECT TEST: array of Animal objects — half Dog, half Cat.
       Every animal is deleted directly as an Animal (virtual
       destructor must chain ~Dog/~Cat -> ~Brain -> ~Animal).
       ============================================================ */
    std::cout << "=== Array of Animals (subject test) ===" << std::endl;
    {
        const int   size = 6;
        Animal*     animals[size];

        for (int k = 0; k < size; k++)
        {
            if (k % 2 == 0)
                animals[k] = new Dog();
            else
                animals[k] = new Cat();
        }

        for (int k = 0; k < size; k++)
        {
            std::cout << "animals[" << k << "] ("
                      << animals[k]->getType() << "): ";
            animals[k]->makeSound();
        }

        for (int k = 0; k < size; k++)
            delete animals[k];      // deleted as Animals: no leak allowed
    }

    /* ============================================================
       SUBJECT TEST: basic polymorphic creation/deletion
       ============================================================ */
    std::cout << "\n=== Polymorphic delete (subject test) ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;
        i->makeSound();
        j->makeSound();

        delete j;
        delete i;
    }

    /* ============================================================
       DEEP COPY: copy constructor — modifying the copy's Brain
       must NOT affect the original.
       ============================================================ */
    std::cout << "\n=== Deep copy: copy constructor ===" << std::endl;
    {
        Dog original;
        original.getBrain()->setIdea(0, "I want a bone!");

        Dog copy(original);
        copy.getBrain()->setIdea(0, "I want to chase cars!");

        std::cout << "original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy     idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;
    }

    /* ============================================================
       DEEP COPY: copy assignment + self-assignment safety
       ============================================================ */
    std::cout << "\n=== Deep copy: assignment operator ===" << std::endl;
    {
        Cat original;
        original.getBrain()->setIdea(0, "I hate Mondays");

        Cat assigned;
        assigned = original;
        assigned.getBrain()->setIdea(0, "I love lasagna");

        std::cout << "original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "assigned idea[0]: " << assigned.getBrain()->getIdea(0) << std::endl;

        assigned = assigned;    // self-assignment must be harmless
        std::cout << "after self-assign: " << assigned.getBrain()->getIdea(0) << std::endl;
    }

    /* ============================================================
       WRONG HIERARCHY: makeSound is NOT virtual here,
       so the WrongAnimal sound is printed through a base pointer.
       ============================================================ */
    std::cout << "\n=== WrongAnimal / WrongCat (no virtual) ===" << std::endl;
    {
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << wrongCat->getType() << std::endl;
        wrongCat->makeSound();          // prints the WrongAnimal sound

        delete wrongCat;
    }

    return 0;
}
