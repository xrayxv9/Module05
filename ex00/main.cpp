#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat steph = Bureaucrat();
	Bureaucrat bernard = Bureaucrat("bernard", 1);


	try
	{
		Bureaucrat error = Bureaucrat("bernard", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl; 
	}

	try
	{
		Bureaucrat error2 = Bureaucrat("bernard", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl; 
	}

	try
	{
		steph.decrement();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[1;031mError: " << e.what() << " detected while decrementing " << steph.getName() << "\033[1;0m" << std::endl;
	}
	try
	{
		bernard.increment();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[1;031mError: " << e.what() << " detected while incrementing " << bernard.getName() << "\033[1;0m"<< std::endl;
	}

	std::cout << bernard << std::endl;
	std::cout << steph << std::endl;
}
