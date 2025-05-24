#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	steph = Bureaucrat();
	Bureaucrat	bernard = Bureaucrat("bernard", 1);
	Form		form = Form("first contract", 75, 75);

	std::cout << form << std::endl;
	try
	{
		steph.signForm(form);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "\033[1;031mError: " << e.what() << " while signing " << form.getName() << "\033[1;0m"<< std::endl;
	}

	try
	{
		bernard.signForm(form);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "\033[1;031mError: " << e.what() << " while signing " << form.getName() << "\033[1;0m"<< std::endl;
	}

	try
	{
		bernard.signForm(form);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "\033[1;031mError: " << e.what() << " while signing " << form.getName() << "\033[1;0m"<< std::endl;
	}

	std::cout << bernard << std::endl;
	std::cout << steph << std::endl;
}
