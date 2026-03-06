#include "Zombie.hpp"

int	main(void)
{
	Zombie	zb = Zombie("Jack");
	Zombie	bz = Zombie();

	zb.announce();
	bz.announce();
}
