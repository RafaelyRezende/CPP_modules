#pragma once

# include <iostream>

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
	~Contact();

	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickname(std::string str);
	void		setPhoneNumber(std::string str);
	void		setSecret(std::string str);

	void		displayFullName();

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getSecret();
};
