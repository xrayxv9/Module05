#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	// init

	Form();
	Form( std::string name );
	Form( int gradeToSign, int gradeToExecute );
	Form( std::string name, int gradeToSign, int gradeToExecute );


	// cpy
	Form( const Form& cpy );

	// overload
	Form& operator=( const Form& cpy );

	// destructor
	~Form();

	//getter
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getSigned() const;

	void beSigned(const Bureaucrat& employee);
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream &o, const Form &self );
