#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <PresidentialPardonForm.hpp>

int main(void)
{
	Bureaucrat	arthur = Bureaucrat();
	Bureaucrat	zaphod = Bureaucrat("zaphod", 1);
	Intern intern = Intern();
	AForm *marvin = intern.makeForm("robotomy request", "Arthur Dent"); 
	AForm *shrubb= intern.makeForm("shrubbery creation", "strawberry"); 
	AForm *president = intern.makeForm("presidential pardon", "Trillian");

	try
	{
		AForm *solanum = intern.makeForm("I am a nomai", "Solanum");
		solanum->beSigned(zaphod);
	}
	catch (Intern::UnknownName &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "TEST ON THE SHRUBBERY" << std::endl << std::endl;

	zaphod.executeForm(*shrubb);
	arthur.executeForm(*shrubb);
	zaphod.signForm(*shrubb);
	zaphod.executeForm(*shrubb);

	std::cout << std::endl;

	std::cout << "TEST ON THE PRESIDENTIAL" << std::endl << std::endl;

	try
	{
		zaphod.executeForm(*president);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	zaphod.signForm(*president);
	arthur.executeForm(*president);
	zaphod.executeForm(*president);

	std::cout << std::endl;
	std::cout << "TEST ON THE ROBOTOMY" << std::endl << std::endl;

	try
	{
		zaphod.executeForm(*marvin);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	zaphod.signForm(*marvin);
	arthur.executeForm(*marvin);
	zaphod.executeForm(*marvin);

	delete president;
	delete marvin;
	delete shrubb;
}
