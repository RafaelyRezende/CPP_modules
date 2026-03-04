#pragma once

# include <iostream>
# include <stdio.h>

# define MAX_CONTACTS 8

class Contact
{
private:

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string darkestSecret;

public:

	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickname(std::string str);
	void		setPhoneNumber(std::string str);
	void		setSecret(std::string str);

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getSecret();
};

class PhoneBook
{
private:
	Contact			list[MAX_CONTACTS];
	unsigned int	i;

public:
	PhoneBook();
	~PhoneBook();
	
	void	setContact();
	void	

};
