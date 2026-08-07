#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

/* Abstract base class: it has a pure virtual function (executeAction),
   so AForm itself can never be instantiated. */
class AForm
{
private:
	/* Attributes stay PRIVATE and live in the BASE class,
	   as required by the subject. */
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;

public:
	/* Orthodox Canonical Form */
	AForm();
	AForm(const std::string& name, int gradeSign, int gradeExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();	// virtual: objects are deleted through AForm* in ex03

	/* Getters */
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;

	void	beSigned(const Bureaucrat& b);

	/* Template Method: execute() performs the common checks here
	   in the base class, then dispatches to the concrete action.
	   This is the "more elegant" way the subject hints at:
	   no duplicated checks in every derived class. */
	void	execute(const Bureaucrat& executor) const;

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	/* Pure virtual: every concrete form must define its own action. */
	virtual void	executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
