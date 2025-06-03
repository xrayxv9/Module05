#pragma  once

#include <exception>
#include <iostream>

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( const Intern &intern );

		~Intern();

		Intern& operator=( const Intern &intern );

		AForm *makeForm( const std::string nameOfForm, const std::string targetOfForm );

		class UnknownName : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		
};

