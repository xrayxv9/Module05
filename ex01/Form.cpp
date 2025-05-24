#include "Form.hpp"
#include <Bureaucrat.hpp>

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form( std::string name ): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form( int gradeToExecute, int gradeToSign ): _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw GradeTooLowException();
	else if (this->_gradeToExecute <= 0 || this->_gradeToSign <= 0)
		throw GradeTooHighException();
}

Form::Form( std::string name, int gradeToExecute, int gradeToSign ): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw GradeTooLowException();
	else if (this->_gradeToExecute <= 0 || this->_gradeToSign <= 0)
		throw GradeTooHighException();
}

Form::Form( const Form &cpy ): _name(cpy._name), _signed(cpy._signed), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
	*this = cpy;
}

Form& Form::operator=( const Form &cpy )
{
	if (this != &cpy)
		return *this;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

std::string Form::getSigned() const
{
	if (this->_signed)
		return ("The form has been signed");
	return ("The form has not been signed");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

std::ostream& operator<<(std::ostream &o, const Form &self)
{
	o << self.getName() << " needs a grade of " << self.getGradeToSign() << " to be signed, and a grade of " << self.getGradeToExecute() << " to be executed." << self.getSigned();
	return o;
}

void Form::beSigned(const Bureaucrat& employee)
{
	if ((employee.getGrade() <= this->_gradeToSign) && _signed == false)
	{
		std::cout << "The Form is now signed" << std::endl;
		_signed = true;
	}
	else if ((employee.getGrade() <= this->_gradeToSign) && _signed == true)
		std::cout << this->_name << " has already been signed" << std::endl;
	else
		throw GradeTooLowException();
}
