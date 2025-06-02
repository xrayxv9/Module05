#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <PresidentialPardonForm.hpp>

int main(void)
{
	Bureaucrat	arthur = Bureaucrat();
	Bureaucrat	zaphod = Bureaucrat("zaphod", 1);
	ShrubberyCreationForm shrubb = ShrubberyCreationForm("strawberry");
	PresidentialPardonForm president = PresidentialPardonForm("Arthur Dent");
	RobotomyRequestForm marvin = RobotomyRequestForm("trillian");

	std::cout << "TEST ON THE SHRUBBERY" << std::endl << std::endl;

	zaphod.executeForm(shrubb);
	arthur.executeForm(shrubb);
	zaphod.signForm(shrubb);
	zaphod.executeForm(shrubb);

	std::cout << std::endl;

	std::cout << "TEST ON THE PRESIDENTIAL" << std::endl << std::endl;

	try
	{
		zaphod.executeForm(president);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	zaphod.signForm(president);
	arthur.executeForm(president);
	zaphod.executeForm(president);

	std::cout << std::endl;
	std::cout << "TEST ON THE ROBOTOMY" << std::endl << std::endl;

	try
	{
		zaphod.executeForm(marvin);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	zaphod.signForm(marvin);
	arthur.executeForm(marvin);
	zaphod.executeForm(marvin);
}
