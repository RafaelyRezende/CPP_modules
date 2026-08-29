#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

/* Required grades: sign 72, exec 45.
   Action: drilling noises, then 50% chance of successful robotomy. */
class RobotomyRequestForm : public AForm
{
private:
	const std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

private:
	virtual void	executeAction() const;
};

#endif
