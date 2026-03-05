#pragma once

# include <iostream>
# include <iomanip>

# define TRUNC 10

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	Contact(std::string str[5]);
	~Contact();

	void		displayEntries(int idx, unsigned int flag);
};
