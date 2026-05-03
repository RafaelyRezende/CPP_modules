#include <iostream>
#include "ScavTrap.h"

int main(void) {
	std::cout << "=== Construction ===" << std::endl;
	ScavTrap serena("Serena");
	
	std::cout << "\n=== Actions ===" << std::endl;
	serena.attack("Bandit");
	serena.takeDamage(30);
	serena.beRepaired(15);
	serena.guardGate();
	
	std::cout << "\n=== Copy ===" << std::endl;
	ScavTrap copySerena(serena);
	copySerena.attack("Another Bandit");
	
	std::cout << "\n=== Assignment ===" << std::endl;
	ScavTrap assigned;
	assigned = serena;
	
	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
