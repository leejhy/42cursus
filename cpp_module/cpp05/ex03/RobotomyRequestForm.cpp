
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : Form(){
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: Form(obj){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{(void)obj; return *this;}

RobotomyRequestForm::RobotomyRequestForm\
(const std::string& target)
: Form(target+"_name", 72, 45){
	this->target = target;
}

void	RobotomyRequestForm::robotomize() const{
	int	random;

	std::cout << "drilling drilling\n";
	srand((unsigned int)time(NULL));
	random = rand();
	if (rand() % 2 == 1)
		std::cout << this->target << " Robotomize SUCCESS!\n";
	else
		std::cout << this->target << " Robotomize FAIL!\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	//서명되었는지 확인하고, 등급확인하고 throw
	if (!this->getCheck())
		throw FormIsNotSigned();
	if (this->getExecuteGrade() < executor.getGrade())//executor가 더 크면 등급이 낮음, 같으면 실행가능
		throw GradeTooLowException();
	this->robotomize();
}
