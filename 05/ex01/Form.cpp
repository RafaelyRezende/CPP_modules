#include "Form.hpp"

Form::Form() : name("N/A"), isSigned(false),
               gradeSign(3), gradeExec(50)
{}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{}

Form::Form(const std::string& name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Execption: grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Execption: grade too low";
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeSign() const
{
    return gradeSign;
}

int Form::getGradeExec() const 
{
    return gradeExec;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o,const Form& f)
{
	o << "Form \"" << f.getName() << "\" ["
	   << (f.getIsSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << f.getGradeSign()
	   << ", grade to execute: " << f.getGradeExec() << "]";
	return o;
}
