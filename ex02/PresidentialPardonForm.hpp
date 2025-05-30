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
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;
	std::string _target;
};
