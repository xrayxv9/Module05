#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	// construcors

	Bureaucrat();
	Bureaucrat( int grade );
	Bureaucrat( const std::string );
	Bureaucrat( const std::string, int grade );

	//destructor
	~Bureaucrat();

	// copy
	Bureaucrat( const Bureaucrat& cpy);

	//overload
	Bureaucrat& operator=( const Bureaucrat& cpy);

	// getter
	int	getGrade() const ;
	std::string getName() const;
	
	// function to change the grade
	void increment();
	void decrement();

	// class to throw exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	void signForm(AForm& form);
	void executeForm(const AForm& form);


private:
	void setGrade(int grade);
	const std::string _name;
	int	_grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& self);
