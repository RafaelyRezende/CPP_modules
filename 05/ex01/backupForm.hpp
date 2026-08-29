#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
private:
	/* All attributes PRIVATE as required by the subject.
	   Grades are const: a form's requirements never change. */
	const std::string	_name;
	bool				_signed;		// always false at construction
	const int			_gradeSign;		// grade required to sign
	const int			_gradeExec;		// grade required to execute

public:
	/* Orthodox Canonical Form */
	Form();
	Form(const std::string& name, int gradeSign, int gradeExec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	/* Getters */
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;

	/* Sign the form if the bureaucrat's grade is high enough
	   (grade number <= required grade number). */
	void	beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
