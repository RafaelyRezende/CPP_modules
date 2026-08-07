#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "== SUBJECT REQUIRED TESTS             ==" << std::endl;
    std::cout << "========================================" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== WRONGANIMAL / WRONGCAT TESTS       ==" << std::endl;
    std::cout << "========================================" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongCat;
    delete wrongMeta;

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== STACK OBJECT TESTS                 ==" << std::endl;
    std::cout << "========================================" << std::endl;

    Animal a;
    Dog d;
    Cat c;

    std::cout << "a type: " << a.getType() << std::endl;
    std::cout << "d type: " << d.getType() << std::endl;
    std::cout << "c type: " << c.getType() << std::endl;
    a.makeSound();
    d.makeSound();
    c.makeSound();

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== COPY CONSTRUCTOR TESTS             ==" << std::endl;
    std::cout << "========================================" << std::endl;

    Dog originalDog;
    Cat originalCat;

    std::cout << "--- Copying Dog ---" << std::endl;
    Dog copyDog(originalDog);
    std::cout << "originalDog type: " << originalDog.getType() << std::endl;
    std::cout << "copyDog type: " << copyDog.getType() << std::endl;
    copyDog.makeSound();

    std::cout << "--- Copying Cat ---" << std::endl;
    Cat copyCat(originalCat);
    std::cout << "originalCat type: " << originalCat.getType() << std::endl;
    std::cout << "copyCat type: " << copyCat.getType() << std::endl;
    copyCat.makeSound();

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== ASSIGNMENT OPERATOR TESTS          ==" << std::endl;
    std::cout << "========================================" << std::endl;

    Dog assignDog;
    Cat assignCat;
    Dog targetDog;
    Cat targetCat;

    std::cout << "--- Assigning Dog ---" << std::endl;
    targetDog = assignDog;
    std::cout << "targetDog type: " << targetDog.getType() << std::endl;

    std::cout << "--- Assigning Cat ---" << std::endl;
    targetCat = assignCat;
    std::cout << "targetCat type: " << targetCat.getType() << std::endl;

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== SELF-ASSIGNMENT TESTS              ==" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== POLYMORPHIC ARRAY TESTS            ==" << std::endl;
    std::cout << "========================================" << std::endl;

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int idx = 0; idx < 4; idx++) {
        std::cout << "Animal[" << idx << "] type: " << animals[idx]->getType() << std::endl;
        animals[idx]->makeSound();
    }

    for (int idx = 0; idx < 4; idx++) {
        delete animals[idx];
    }

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== DESTRUCTOR ORDER VERIFICATION      ==" << std::endl;
    std::cout << "========================================" << std::endl;

    {
        std::cout << "Creating Dog in inner scope..." << std::endl;
        Dog scopedDog;
        std::cout << "Leaving inner scope..." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "== END OF MAIN                        ==" << std::endl;
    std::cout << "========================================" << std::endl;

    return (0);
}
