#include <iostream>
#include "ClapTrap.h"

int main(void) {
	ClapTrap bob("Bob");
	ClapTrap jim("Jim");
	
	bob.attack("Jim");
	jim.takeDamage(0);
	
	jim.attack("Bob");
	bob.takeDamage(0);
	
	bob.beRepaired(5);
	jim.beRepaired(3);
	
	jim.takeDamage(15);
	jim.attack("Bob");
	jim.beRepaired(10);
	
	ClapTrap copyBob(bob);
	copyBob.attack("Jim");
	
	ClapTrap assigned;
	assigned = jim;
	
	return 0;
}
