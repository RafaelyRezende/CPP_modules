#pragma once

# include <iostream>
# include <string>

class	Zombie
{
private:
	std::string	_name;
	int			_n;
	Zombie		*ptr;

public:
	Zombie();
	~Zombie();

	void	setName(std::string name);
	void	setN(int n);

	Zombie	*zombieHorde(int N, std::string name);
	void	announce(int i);
};
