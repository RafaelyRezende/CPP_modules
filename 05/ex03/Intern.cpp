#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/* ---------------- Orthodox Canonical Form ----------------
   All trivial: the Intern holds no data. */

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

/* ---------------- Creators ---------------- */

AForm* Intern::createShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

/* ---------------- makeForm ----------------
   Lookup table of (form name, pointer-to-member-creator) pairs.
   This replaces the forbidden "excessive if/else if/else" mess:
   adding a new form type means adding ONE table entry + ONE creator. */

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	struct FormEntry
	{
		std::string	name;
		AForm*		(Intern::*create)(const std::string&) const;
	};

	const FormEntry table[] = {
		{ "shrubbery creation",   &Intern::createShrubbery },
		{ "robotomy request",     &Intern::createRobotomy },
		{ "presidential pardon",  &Intern::createPardon }
	};
	const size_t tableSize = sizeof(table) / sizeof(table[0]);

	for (size_t i = 0; i < tableSize; i++)
	{
		if (table[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*table[i].create)(target);
		}
	}
	std::cout << "Intern cannot create \"" << formName
			  << "\": unknown form name." << std::endl;
	return NULL;
}
