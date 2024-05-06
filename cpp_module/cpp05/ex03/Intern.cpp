
#include "Intern.hpp"
#include <iostream>

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern& obj){(void)obj;}
Intern& Intern::operator=(const Intern& obj){(void)obj; return *this;}

Form* Intern::makeShu(std::string target){
	return (new ShrubberyCreationForm(target));
}
Form* Intern::makePres(std::string target){
	return (new PresidentialPardonForm(target));
}
Form* Intern::makerobo(std::string target){
	return (new RobotomyRequestForm(target));
}

Form* Intern::makeForm(const std::string& name, const std::string& target){
	std::string names[3] = \
	{"shrubbery creation", "robotomy request", "presidential pardon"};

	Form *(Intern::*f[3])(std::string) = { 
		&Intern::makeShu,\
		&Intern::makerobo,\
		&Intern::makePres };
	for (int i = 0; i < 3; i++){
		if (names[i] == name){
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*f[i])(target));
		}
	}
	throw IsNotExist();
	return (NULL);
}

const char* Intern::IsNotExist::what () const throw (){
	return "*===EXCEPTION FORM NAME IS NOT EXIST===*";
}