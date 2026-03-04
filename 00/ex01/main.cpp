#include "Contact.hpp"

int	main()
{
	std::string	name = "Rafael Luis";
	std::string	surname = "Yanase de Rezende";

	Contact person1;

	person1.setFirstName(name);
	person1.setLastName(surname);
	person1.displayFullName();
}
