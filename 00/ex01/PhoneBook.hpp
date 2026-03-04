#pragma once

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact			list[MAX_CONTACTS];
	unsigned int	i;

public:
	PhoneBook();
	~PhoneBook();
	
	void			addContact();
	void			displayFirstName();

};
