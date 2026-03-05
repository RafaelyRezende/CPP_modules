#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->i = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact() {
	std::string		line;
	unsigned int	index = this->i % MAX_CONTACTS;

	Contact& p = this->list[index];

	std::cout << "Enter first name: ";
	std::getline(std::cin, line);
	p.setFirstName(line);
	this->i++;
}

void	PhoneBook::searchContact() {
	std::cout << "Select contact:" << std::endl;
}
