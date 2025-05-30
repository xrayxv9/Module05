#include "ShrubberyCreationForm.hpp"
#include <Bureaucrat.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): _gradeToSign(145), _gradeToExecute(137), _signed(false), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): _gradeToSign(145), _gradeToExecute(137), _signed(false), _target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy)
{
	if (this != &cpy)
	{
		this->_target = cpy._target;
		this->_signed = cpy._signed;
		return *this;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &employee) const
{
	if (employee.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else if (this->_signed == false)
		throw FormNotSignedException();
	else
	{
		std::string final = this->_target + "_shrubbery";
		std::ofstream outfile(final.c_str());
		outfile << "      /\\            /\\      " << std::endl;
		outfile << "     /\\*\\          /\\*\\     " << std::endl;
		outfile << "    /\\O\\*\\        /\\O\\*\\    " << std::endl;
		outfile << "   /*/\\/\\/\\      /*/\\/\\/\\   " << std::endl;
		outfile << "  /\\O\\/\\*\\/\\    /\\O\\/\\*\\/\\  " << std::endl;
		outfile << " /\\*\\/\\*\\/\\/\\  /\\*\\/\\*\\/\\/\\ " << std::endl;
		outfile << "/\\O\\/\\/*/\\/O/\\/\\O\\/\\/*/\\/O/\\" << std::endl;
		outfile << "       ||            ||      " << std::endl;
		outfile << "       ||            ||      " << std::endl;
		outfile << "       ||            ||      " << std::endl;
	}
}
