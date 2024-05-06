
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : Form(){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: Form(obj){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{(void)obj; return *this;}

PresidentialPardonForm::PresidentialPardonForm\
(const std::string& target)
: Form(target+"_name", 25, 5){
	this->target = target;
}

void	PresidentialPardonForm::inForm() const{
	std::cout << this->target << " has been pardoned by Zaphod Beebelbrox\n";
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	//서명되었는지 확인하고, 등급확인하고 throw
	if (!this->getCheck())
		throw FormIsNotSigned();
	if (this->getExecuteGrade() < executor.getGrade())//executor가 더 크면 등급이 낮음, 같으면 실행가능
		throw GradeTooLowException();
	inForm();
}
