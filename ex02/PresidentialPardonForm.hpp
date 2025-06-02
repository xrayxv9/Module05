#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm( std::string target );

	~PresidentialPardonForm();
	
	PresidentialPardonForm( const PresidentialPardonForm& cpy);

	PresidentialPardonForm& operator=( const PresidentialPardonForm& cpy);

	void execute(const Bureaucrat &employee) const;


private:
	std::string _target;
};
