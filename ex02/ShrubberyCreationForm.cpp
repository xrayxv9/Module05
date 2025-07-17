#include "ShrubberyCreationForm.hpp"
#include <Bureaucrat.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy)
{
	if (this != &cpy)
		this->_target = cpy._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &employee) const
{
	if (employee.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() != "The form has been signed")
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
