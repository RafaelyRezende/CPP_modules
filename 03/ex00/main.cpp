#include "ClapTrap.hpp"

int main(void) {
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
	
	return 0;
}
