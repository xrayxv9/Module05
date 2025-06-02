#include "Bureaucrat.hpp"
#include <AForm.hpp>
#include <ostream>

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(int grade ): _name("default")
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade ): _name(name)
{
	setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
{
	*this = cpy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cpy)
{
	if (this != &cpy)
		this->_grade = cpy._grade;
	return *this;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

void Bureaucrat::increment()
{
	setGrade(this->_grade - 1);
}

void Bureaucrat::decrement()
{
	setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}


void Bureaucrat::setGrade(int grade)
{	
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& self)
{
	o << self.getName() << ", bureaucrat grade " << self.getGrade();
	return (o);
}

void Bureaucrat::signForm(AForm& form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << "'s form"<< std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << " to execute the Form "<< std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
