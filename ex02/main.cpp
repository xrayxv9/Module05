#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <PresidentialPardonForm.hpp>

int main(void)
{
	Bureaucrat	steph = Bureaucrat();
	Bureaucrat	bernard = Bureaucrat("bernard", 1);
	ShrubberyCreationForm shrubb = ShrubberyCreationForm("strawberry");
	PresidentialPardonForm president = PresidentialPardonForm("Arthur Dent");

	std::cout << "TEST ON THE SHRUBBERY" << std::endl << std::endl;

	bernard.executeForm(shrubb);
	steph.executeForm(shrubb);
	bernard.signForm(shrubb);
	bernard.executeForm(shrubb);

	std::cout << std::endl;
	std::cout << "TEST ON THE PRESIDENTIAL" << std::endl << std::endl;

	try
	{
		bernard.executeForm(president);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	bernard.signForm(president);
	steph.executeForm(president);
}
