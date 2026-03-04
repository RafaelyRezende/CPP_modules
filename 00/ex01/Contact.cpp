#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void		Contact::setFirstName(std::string str) {firstName = str;}

void		Contact::setLastName(std::string str) {lastName = str;}

void		Contact::setNickname(std::string str) {nickname = str;}

void		Contact::setPhoneNumber(std::string str) {phoneNumber = str;}

void		Contact::setSecret(std::string str) {darkestSecret = str;}

std::string	Contact::getFirstName() {return firstName;}

std::string	Contact::getLastName() {return lastName;}

std::string	Contact::getNickname() {return nickname;}

std::string	Contact::getPhoneNumber() {return phoneNumber;}

std::string	Contact::getSecret() {return darkestSecret;}

void		Contact::displayFullName() {
	std::cout << Contact::getFirstName() << " " << Contact::getLastName() << std::endl;
}
