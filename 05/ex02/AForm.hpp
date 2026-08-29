#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class AForm 
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
        const int           _gradeExec;
    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        virtual ~AForm();

        const std::string&  getName() const;
        bool                getIsSigned() const;
        int           getGradeSign() const;
        int           getGradeExec() const;
};

#endif
