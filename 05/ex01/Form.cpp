#include "Form.hpp"

/* ---------------- Orthodox Canonical Form ---------------- */

Form::Form()
	: _name("Default form"), _signed(false), _gradeSign(150), _gradeExec(150)
{
}

Form::Form(const std::string& name, int gradeSign, int gradeExec)
	: _name(name), _signed(false),
	  _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed),
	  _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
}

/* Const members cannot be reassigned; only the mutable flag is copied. */
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form()
{
}

/* ---------------- Getters ---------------- */

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExec() const
{
	return _gradeExec;
}

/* ---------------- beSigned ----------------
   Grade 1 is the highest, so "high enough" means
   the bureaucrat's grade number is <= the required number. */

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

/* ---------------- Exceptions ---------------- */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: grade too high (maximum is grade 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: grade too low";
}

/* ---------------- operator<< ---------------- */

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form \"" << f.getName() << "\" ["
	   << (f.getSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << f.getGradeSign()
	   << ", grade to execute: " << f.getGradeExec() << "]";
	return os;
}
