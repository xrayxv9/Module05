#include "PresidentialPardonForm.hpp"
#include <Bureaucrat.hpp>

PresidentialPardonForm::PresidentialPardonForm(): _gradeToSign(145), _gradeToExecute(137), _signed(false), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): _gradeToSign(145), _gradeToExecute(137), _signed(false), _target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy)
{
	if (this != &cpy)
	{
		this->_target = cpy._target;
		this->_signed = cpy._signed;
		return *this;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &employee) const
{
	if (employee.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else if (this->_signed == false)
		throw FormNotSignedException();
	else
		std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox the president of the galaxy" << std::endl;

}

