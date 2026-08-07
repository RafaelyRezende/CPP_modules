#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

/* Required grades: sign 145, exec 137.
   Action: create <target>_shrubbery and write ASCII trees into it. */
class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();

private:
	virtual void	executeAction() const;
};

#endif
