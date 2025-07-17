#include "PresidentialPardonForm.hpp"
#include <Bureaucrat.hpp>

PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential pardon", 72, 45), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("presidential pardon", 72, 45), _target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy)
{
	if (this != &cpy)
		this->_target = cpy._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &employee) const
{
	if (employee.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() != "The form has been signed")
		throw FormNotSignedException();
	else
		std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox the president of the galaxy" << std::endl;
}

