#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	// init

	AForm();
	AForm( std::string name );
	AForm( int gradeToSign, int gradeToExecute );
	AForm( std::string name, int gradeToSign, int gradeToExecute );


	// cpy
	AForm( const AForm& cpy );

	// overload
	AForm& operator=( const AForm& cpy );

	// destructor
	virtual ~AForm();

	//getter
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getSigned() const;

	void beSigned(const Bureaucrat& employee );
	virtual void execute(const Bureaucrat& employee ) const = 0;

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
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream &o, const AForm &self );
