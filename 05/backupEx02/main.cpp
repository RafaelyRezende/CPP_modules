#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>	// std::srand
#include <ctime>	// std::time

int main()
{
	std::srand(std::time(NULL));	// seed the PRNG once for robotomy

	/* --- AForm is abstract: this would NOT compile ---
	   AForm f("test", 10, 10); */

	/* --- Shrubbery: full happy path --- */
	std::cout << "=== ShrubberyCreationForm ===" << std::endl;
	{
		Bureaucrat gardener("Gardener", 140);	// can sign (145) and exec (137)? exec needs <= 137
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		gardener.signForm(shrub);
		gardener.executeForm(shrub);	// 140 > 137: expect failure
		Bureaucrat chief("Chief", 130);
		chief.executeForm(shrub);		// 130 <= 137: success, creates home_shrubbery
	}

	/* --- Robotomy: 50% success --- */
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	{
		Bureaucrat tech("Technician", 40);
		RobotomyRequestForm robo("Bender");
		tech.signForm(robo);
		tech.executeForm(robo);
		tech.executeForm(robo);
		tech.executeForm(robo);
	}

	/* --- Presidential pardon --- */
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		president.signForm(pardon);
		president.executeForm(pardon);
	}

	/* --- Executing an unsigned form --- */
	std::cout << "\n=== Execute unsigned form ===" << std::endl;
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Ford Prefect");
		president.executeForm(pardon);	// not signed -> error message
	}

	/* --- Grade too low to sign --- */
	std::cout << "\n=== Grade too low to sign ===" << std::endl;
	{
		Bureaucrat lowly("Lowly", 150);
		PresidentialPardonForm pardon("Trillian");
		lowly.signForm(pardon);
		lowly.executeForm(pardon);
	}

	return 0;
}
