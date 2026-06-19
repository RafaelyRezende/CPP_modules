#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
<<<<<<< HEAD
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
=======
    : _name("Default"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
    _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
>>>>>>> feature/module02
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
<<<<<<< HEAD
	if (this != &other)
	{
		_name = other._name;
		_healthPoints = other._healthPoints;
		_energyPoints = other._energyPoints;
		_attackPoints = other._attackPoints;
	}

	std::cout << "Copy assigment call" << std::endl;
	return *this;
=======
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
>>>>>>> feature/module02
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

<<<<<<< HEAD
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
=======
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already destroyed and cannot take more damage!" << std::endl;
        return;
    }
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
    }
    else
    {
        _hitPoints -= amount;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair itself because it has no hit points left!" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair itself because it has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current hit points: " << _hitPoints << std::endl;
>>>>>>> feature/module02
}
