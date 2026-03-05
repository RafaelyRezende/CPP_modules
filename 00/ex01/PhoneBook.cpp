#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->i = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	const char	*args[] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
	};
	std::string		tmp[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << args[i];
		if (!std::getline(std::cin, tmp[i]) || tmp[i].empty())
		{
			std::cerr << "Error creating entry, empty input" << std::endl;
			return ;
		}
	}

	unsigned int	index = this->i % MAX_CONTACTS;
	this->list[index] = Contact(tmp);
	this->i++;
}

void	PhoneBook::displayEntry(const char *c)
{
	if (*(c + 1) == '\0' && *c >= '1' && *c <= '8')
		this->list[*c - '0' - 1].displayEntries(*c - '0', 0);
	else
		std::cout << "Invalid index" << std::endl;
}

void	PhoneBook::searchContact() {
	std::string	line;

	std::cout << std::endl;
	std::cout << std::right << std::setfill(' ') << std::setw(10);
	std::cout << "INDEX" << "|" << "FIRST NAME" << "|" << "LAST  NAME" << "|" << "  NICKNAME" << std::endl;
	for (int idx = 0; idx < MAX_CONTACTS; idx++)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(10);
		this->list[idx].displayEntries(idx + 1, 1);
	}
	std::cout << std::endl;
	std::cout << "Select contact:" << std::endl;
	std::getline(std::cin, line);
	this->displayEntry((const char*)line.c_str());
}
