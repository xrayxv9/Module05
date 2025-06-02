#include "AForm.hpp"
#include <Bureaucrat.hpp>

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm( std::string name ): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm( int gradeToExecute, int gradeToSign ): _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw GradeTooLowException();
	else if (this->_gradeToExecute <= 0 || this->_gradeToSign <= 0)
		throw GradeTooHighException();
}

AForm::AForm( std::string name, int gradeToExecute, int gradeToSign ): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw GradeTooLowException();
	else if (this->_gradeToExecute <= 0 || this->_gradeToSign <= 0)
		throw GradeTooHighException();
}

AForm::AForm( const AForm &cpy ): _name(cpy._name), _signed(cpy._signed), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
	*this = cpy;
}

AForm& AForm::operator=( const AForm &cpy )
{
	if (this != &cpy)
		return *this;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

std::string AForm::getSigned() const
{
	if (this->_signed)
		return ("The form has been signed");
	return ("The form has not been signed");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("The form has never been signed, therefore you cannot execute it");
}

std::ostream& operator<<(std::ostream &o, const AForm &self)
{
	o << self.getName() << " needs a grade of " << self.getGradeToSign() << " to be signed, and a grade of " << self.getGradeToExecute() << " to be executed." << self.getSigned();
	return o;
}

void AForm::beSigned(const Bureaucrat& employee)
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
