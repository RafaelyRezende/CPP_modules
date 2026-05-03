#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    _name = "Default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap parameterized constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
    ScavTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "ClapTrap name:    " << ClapTrap::_name << std::endl;
}
