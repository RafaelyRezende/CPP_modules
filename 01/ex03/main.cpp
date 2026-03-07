#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");
	
		HumanA	bob("Bob Vance", club);
		bob.attack();
		club.setType("excalibur");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
	
		HumanB	jimmy("Jimmy Cash");
		jimmy.setWeapon(club);
		jimmy.attack();
		club.setType("charisma");
		jimmy.attack();
	}

}
