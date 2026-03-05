#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string str[5]) {
	this->firstName = str[0];
	this->lastName = str[1];
	this->nickname = str[2];
	this->phoneNumber = str[3];
	this->darkestSecret = str[4];
}

Contact::~Contact() {}

void	Contact::displayEntries(int idx, unsigned int flag) {
	if (flag)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(10);
		std::cout << idx << "|" ;
		std::cout << std::right << std::setfill(' ') << std::setw(10);
		std::cout << this->firstName<< "|" ;
		std::cout << std::right << std::setfill(' ') << std::setw(10);
		std::cout << this->lastName << "|" ;
		std::cout << std::right << std::setfill(' ') << std::setw(10);
		std::cout << this->lastName << std::endl;
	}
	else
	{
		std::cout << "First name    : " << this->firstName << std::endl;
		std::cout << "Last name     : " << this->lastName << std::endl;
		std::cout << "Nickname      : " << this->nickname << std::endl;
		std::cout << "Phone number  : " << this->phoneNumber << std::endl;
		std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
	}
}
