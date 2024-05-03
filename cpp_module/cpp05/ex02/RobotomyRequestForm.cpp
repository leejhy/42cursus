
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm(){
	std::cout << "drilling drilling\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: AForm(obj){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{(void)obj; return *this;}

RobotomyRequestForm::RobotomyRequestForm\
(const std::string& name)
: AForm(name, 72, 45){
	this->target = name;
	std::cout << "drilling drilling\n";
}

void	RobotomyRequestForm::beSigned(const Bureaucrat& obj){(void)obj;}

void	RobotomyRequestForm::robotomize(){
	int	random;

	srand((unsigned int)time(NULL));
	random = rand();
	if (rand() % 2 == 1)
		std::cout << this->target << " Robotomize SUCCESS!\n";
	else
		std::cout << this->target << " Robotomize FAIL!\n";
}