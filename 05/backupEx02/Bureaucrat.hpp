#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;	// forward declaration (AForm.hpp includes this header)

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

	/* Form interactions: attempt + self-report */
	void	signForm(AForm& form);
	void	executeForm(const AForm& form) const;

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
