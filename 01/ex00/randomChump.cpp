#include "Zombie.hpp"

void		Zombie::randomChump(std::string name) {
	Zombie	zoom = Zombie(name);
	zoom.announce();
}
