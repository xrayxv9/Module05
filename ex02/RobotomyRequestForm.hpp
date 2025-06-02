#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm( std::string target );

	~RobotomyRequestForm();
	
	RobotomyRequestForm( const RobotomyRequestForm& cpy);

	RobotomyRequestForm& operator=( const RobotomyRequestForm& cpy);

	void execute(const Bureaucrat &employee) const;


private:
	std::string _target;
};
