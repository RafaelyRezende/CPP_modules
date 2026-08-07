#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>	// std::srand
#include <ctime>	// std::time

int main()
{
	std::srand(std::time(NULL));

	Intern	someRandomIntern;
	AForm*	form;

	/* --- Robotomy request (subject's example) --- */
	std::cout << "=== robotomy request ===" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		Bureaucrat tech("Technician", 40);
		tech.signForm(*form);
		tech.executeForm(*form);
		delete form;	// makeForm() allocates with new: we must delete
	}

	/* --- Shrubbery creation --- */
	std::cout << "\n=== shrubbery creation ===" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		Bureaucrat gardener("Gardener", 130);
		gardener.signForm(*form);
		gardener.executeForm(*form);
		delete form;
	}

	/* --- Presidential pardon --- */
	std::cout << "\n=== presidential pardon ===" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form)
	{
		Bureaucrat president("President", 1);
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
	}

	/* --- Unknown form name --- */
	std::cout << "\n=== unknown form ===" << std::endl;
	form = someRandomIntern.makeForm("coffee request", "Kitchen");
	if (form)
		delete form;	// never reached: NULL is returned
	else
		std::cout << "(makeForm returned NULL, nothing to delete)" << std::endl;

	return 0;
}
