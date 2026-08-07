#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

/* Forward declaration instead of #include "Form.hpp":
   Form.hpp already includes this header, and circular includes
   would break the include guards. A declaration is enough here
   because signForm() only takes a Form& (no complete type needed). */
class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;	// 1 (highest) ... 150 (lowest)

public:
	/* Orthodox Canonical Form */
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	/* Getters */
	const std::string&	getName() const;
	int					getGrade() const;

	/* Grade modifiers */
	void	incrementGrade();
	void	decrementGrade();

	/* Attempt to sign a form; reports the outcome itself */
	void	signForm(Form& form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
