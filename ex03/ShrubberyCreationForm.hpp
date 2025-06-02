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
	std::string _target;
};
