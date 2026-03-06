#include "Zombie.hpp"

Zombie::Zombie() {
	this->_n = 0;
	this->_name = "";
	this->ptr = NULL;
}

Zombie::~Zombie() {if (this->ptr)delete[] this->ptr; this->ptr = NULL;}

void	Zombie::setName(std::string name) {_name = name;}

void	Zombie::setN(int n) {_n = n;}

void	Zombie::announce(int i)
{
	std::cout << i<< " "<< this->_name << std::endl;
}
