#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name)
{
	this->ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		this->ptr[i].setName(name);
		this->ptr[i].announce(i);
	}
	return (this->ptr);
}
