#include "Intern.hpp"
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern() {}

Intern& Intern::operator=( const Intern &intern)
{
	if (this != &intern)
		return *this;
	return *this;
}

Intern::~Intern() {}

Intern::Intern( const Intern &cpy)
{
	*this = cpy;
}

const char *Intern::UnknownName::what() const throw()
{
	return ("The name of the form you gave me doesn't exist sir.");
}

static AForm *makeRobot( const std::string targetName )
{
	return (new RobotomyRequestForm(targetName));
}

static AForm *makePresident( const std::string targetName )
{
	return (new PresidentialPardonForm(targetName));
}

static AForm *makeShrub( const std::string targetName )
{
	return (new ShrubberyCreationForm(targetName));
}

AForm *Intern::makeForm( const std::string nameOfForm, const std::string targetName)
{
	AForm *(*allForms[])( const std::string name ) = {&makePresident, &makeRobot, &makeShrub};
	std::string formName[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName[i] == nameOfForm)
		{
			std::cout << "Intern creates " << targetName << std::endl;
			return (allForms[i](targetName));
		}
	}
	throw UnknownName();
}
