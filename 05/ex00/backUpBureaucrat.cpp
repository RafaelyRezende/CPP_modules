#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
}

/* _name is const, so it cannot be reassigned; only the grade is copied. */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

/* ---------------- Getters ---------------- */

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

/* ---------------- Grade modifiers ----------------
   Remember: grade 1 is the HIGHEST, 150 is the LOWEST.
   "Increment" means a promotion: 3 -> 2. */

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

/* ---------------- Exceptions ---------------- */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: grade too high (maximum is grade 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: grade too low (minimum is grade 150)";
}

/* ---------------- operator<< ---------------- */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
