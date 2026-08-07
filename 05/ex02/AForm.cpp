#include "AForm.hpp"

/* ---------------- Orthodox Canonical Form ---------------- */

AForm::AForm()
	: _name("Default form"), _signed(false), _gradeSign(150), _gradeExec(150)
{
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
	: _name(name), _signed(false),
	  _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed),
	  _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
}

/* ---------------- Getters ---------------- */

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExec() const
{
	return _gradeExec;
}

/* ---------------- beSigned ---------------- */

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

/* ---------------- execute (Template Method) ----------------
   1. Verify the form is signed.
   2. Verify the executor's grade is high enough.
   3. Dispatch to the concrete action via dynamic binding. */

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();
	executeAction();
}

/* ---------------- Exceptions ---------------- */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form: grade too high (maximum is grade 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form: grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form: cannot execute, the form is not signed";
}

/* ---------------- operator<< ---------------- */

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form \"" << f.getName() << "\" ["
	   << (f.getSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << f.getGradeSign()
	   << ", grade to execute: " << f.getGradeExec() << "]";
	return os;
}
