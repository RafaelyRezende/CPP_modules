#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : _name("None"),
    _healthPoints(0),
    _energyPoints(0),
    _attackPoints(0)
{
	std::cout << "Default constructor call. ClapTrap alive!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	_healthPoints(10),
	_energyPoints(10),
	_attackPoints(0)
{
	std::cout << "Parameter constructor call" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, int healthPoints, int energyPoints, int attackPoints)
	: _name(name),
	_healthPoints(healthPoints),
	_energyPoints(energyPoints),
	_attackPoints(attackPoints)
{
	std::cout << "Full constructor call" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor call" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	_healthPoints(other._healthPoints),
	_energyPoints(other._energyPoints),
	_attackPoints(other._attackPoints)
{
	std::cout << "Copy constructor call" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_healthPoints = other._healthPoints;
		_energyPoints = other._energyPoints;
		_attackPoints = other._attackPoints;
	}

	std::cout << "Copy assigment call" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_healthPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackPoints << " points of damage." << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " dead or asleep." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_healthPoints -= static_cast<int>(amount);
	if (_healthPoints < 0)
		_healthPoints = 0;
	std::cout << "ClapTrap " << _name << " took " << amount << " damage. HP: " << _healthPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_healthPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repaired " << amount << " points of damage." << std::endl;
        _healthPoints += amount;
        _energyPoints--;
	}
    else
    {
        std::cout << "ClapTrap " << _name << " no helath or energy to be repaired" << std::endl;
    }
}

std::string	ClapTrap::getName() const
{
	return _name;
}

int		ClapTrap::getHitPoints() const
{
	return _healthPoints;
}

int     ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

int     ClapTrap::getAttackPoints() const
{
    return _attackPoints;
}
