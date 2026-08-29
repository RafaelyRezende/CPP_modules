#include "ShrubberyCreationForm.hpp"
#include <fstream>	// std::ofstream
#include <iostream>

/* ---------------- Orthodox Canonical Form ---------------- */

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);	// _target is const: not reassignable
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/* ---------------- Action ----------------
   The base class execute() already checked signature + grade.
   Here we only perform the concrete action: write ASCII trees. */

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "ShrubberyCreationForm: could not create file for target \""
				  << _target << "\"" << std::endl;
		return;
	}
	file << "       ###\n"
		 << "      #o###\n"
		 << "    #####o###\n"
		 << "   #o#\\#|#/###\n"
		 << "    ###\\|/#o#\n"
		 << "     # }|{  #\n"
		 << "       }|{\n"
		 << "\n"
		 << "       ###\n"
		 << "      #o###\n"
		 << "    #####o###\n"
		 << "   #o#\\#|#/###\n"
		 << "    ###\\|/#o#\n"
		 << "     # }|{  #\n"
		 << "       }|{\n";
	file.close();
}
