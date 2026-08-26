#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form 
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeSign;
        const int           gradeExec;
    public:
        Form();
        Form(const std::string& name, int gradeSign, int gradeExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

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
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeSign() const;
        int         getGradeExec() const;

        void        beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& o,const Form& f);
#endif
