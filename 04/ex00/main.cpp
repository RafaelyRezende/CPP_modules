#include "Animal.hpp"

int main()
{
    std::cout << "===== Default and Parameterized Constructors =====" << std::endl;
    Animal a();
    Animal dog("Dog");
    Animal cat("Cat");

    std::cout << "\n===== Copy Constructor =====" << std::endl;
    Animal copyDog(dog);
    Animal copyCat(cat);

    std::cout << "\n===== Make Sound =====" << std::endl;
    dog.makeSound();
    cat.makeSound();
    copyDog.makeSound();
    copyCat.makeSound();

    return (0);
}