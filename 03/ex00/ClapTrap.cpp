#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
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
		std::cout << "ClapTrap " << _name << " sleep." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_healthPoints -= static_cast<int>(amount);
	if (_healthPoints < 0)
		_healthPoints = 0;
	std::cout << "ClapTrap " << _name << " took " << amount << " damage. HP: " << _healthPoints << std::endl;
}

void	ClapTrap::repair(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repaired" << amount << " points of damage." << std::endl;
	}
}

std::string	ClapTrap::getName() const
{
	return _name;
}

int		getHitPoint() const
{
	return _healthPoints;
}

bool		isDead() const
{
	if (_
