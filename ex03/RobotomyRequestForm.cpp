#include "RobotomyRequestForm.hpp"
#include <Bureaucrat.hpp>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cpy)
{
	if (this != &cpy)
		this->_target = cpy._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &employee) const
{
	srand(time(0));

	int randomNumber = rand() % 2;
	if (employee.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() != "The form has been signed")
		throw FormNotSignedException();
	if (randomNumber == 1)
		std::cout << this->_target << " has been robotomized succesfully"<< std::endl;
	else
		std::cout << this->_target << " has resisted the robotomisation" << std::endl;
}
