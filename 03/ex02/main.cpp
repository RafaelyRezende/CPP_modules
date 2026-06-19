#include "FragTrap.h"
#include <iostream>

int main(void)
{
    std::cout << "========================================" << std::endl;
    std::cout << "=== Testing FragTrap Construction    ===" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n--- 1. Default Constructor ---" << std::endl;
    FragTrap defaultFrag;

    std::cout << "\n--- 2. Parameterized Constructor ---" << std::endl;
    FragTrap namedFrag("Bobby");

    std::cout << "\n--- 3. Copy Constructor ---" << std::endl;
    FragTrap copyFrag(namedFrag);

    std::cout << "\n========================================" << std::endl;
    std::cout << "=== Testing FragTrap Functionality   ===" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n--- 4. highFivesGuys (special ability) ---" << std::endl;
    defaultFrag.highFivesGuys();
    namedFrag.highFivesGuys();
    copyFrag.highFivesGuys();

    std::cout << "\n--- 5. Inherited attack from ClapTrap ---" << std::endl;
    namedFrag.attack("a random target");

    std::cout << "\n--- 6. Copy Assignment Operator ---" << std::endl;
    FragTrap assignFrag;
    assignFrag = namedFrag;
    assignFrag.highFivesGuys();

    std::cout << "\n========================================" << std::endl;
    std::cout << "=== Testing Destruction Order        ===" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\n(Objects will be destroyed in reverse\n"
              << "order of construction: LIFO)\n" << std::endl;

    return (0);
}
