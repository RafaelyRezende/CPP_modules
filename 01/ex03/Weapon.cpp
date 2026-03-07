#include "Weapon.hpp"

Weapon::Weapon() {type = "bare hands";}
Weapon::Weapon(std::string t) {type = t;}
Weapon::~Weapon() {}

const std::string&	Weapon::getType() const {return (type);}

void	Weapon::setType(std::string t) {type = t;}

void	Weapon::dispType() {
	std::cout << "Address of member type: ";
	std::cout << &type << std::endl;
	std::cout << "Value of member type: ";
	std::cout << type << std::endl;
}
