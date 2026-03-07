#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
};

HumanB::~HumanB() {};

void	HumanB::setWeapon(Weapon& type) {
	_weapon = &type;
}

void	HumanB::attack() {
	if (_weapon == NULL)
		std::cout << _name << " attacks with their hands" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
