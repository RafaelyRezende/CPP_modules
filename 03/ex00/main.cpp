#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
    //ClapTrap ghost;
    ClapTrap clapOne("Jacob");

    //std::cout << ghost.getName() << std::endl;
    //std::cout << ghost.getHitPoints() << std::endl;

    std::cout << clapOne.getName() << std::endl;
    std::cout << clapOne.getHitPoints() << std::endl;

    clapOne.attack("John");

    /*
	ClapTrap bob("Bob");
	ClapTrap jim("Jim");
	
	bob.attack("Jim");
	jim.takeDamage(0);
	
	jim.attack("Bob");
	bob.takeDamage(0);
	
	bob.repair(5);
	jim.repair(3);
	
	jim.takeDamage(15);
	jim.attack("Bob");
	jim.repair(10);
	
	ClapTrap copyBob(bob);
	copyBob.attack("Jim");
	
	ClapTrap assigned;
	assigned = jim;
    */
	
	return 0;
}
