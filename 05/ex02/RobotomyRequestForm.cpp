#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>	// std::rand

/* ---------------- Orthodox Canonical Form ---------------- */

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* ---------------- Action ----------------
   std::rand() % 2 gives a 50/50 outcome.
   The PRNG is seeded once with std::srand(std::time(NULL)) in main(). */

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* BZZZZZT * DRRRRR * WHIRRRR * (drilling noises) *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy of " << _target << " failed." << std::endl;
}
