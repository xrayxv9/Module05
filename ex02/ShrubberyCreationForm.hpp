#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );

	~ShrubberyCreationForm();
	
	ShrubberyCreationForm( const ShrubberyCreationForm& cpy);

	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& cpy);

	void execute(const Bureaucrat &employee) const;


private:
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;
	std::string _target;

};
