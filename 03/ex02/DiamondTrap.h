#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    using ScavTrap::attack;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void whoAmI();
};

#endif
