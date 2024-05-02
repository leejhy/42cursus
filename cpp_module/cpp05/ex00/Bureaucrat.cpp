
#include "Bureaucrat.hpp"
#include <iostream>
// Bureaucrat();
// ~Bureaucrat();
// Bureaucrat(const Bureaucrat& obj);
// Bureaucrat& operator=(const Bureaucrat& obj);

// const std::string& getName();
// int getGrade();

Bureaucrat::Bureaucrat()
: name("DEFAULT"), grade(150){
	std::cout << "Constructor\n";
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
: name(obj.name), grade(obj.grade){
	std::cout << "Copy\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	// this->name = ? const라서 불가능
	this->grade = obj.grade; 
	std::cout << "Copy assignment\n";
	return *this;
}

const std::string& Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { this->grade; }

void	Bureaucrat::incGrade(){
	if (this->grade - 1 < 1) //highest
		throw ;//예외
	this->grade -= 1;
}

void	Bureaucrat::decGrade(){
	if (this->grade + 1 > 150)
		throw ;
	this->grade += 1;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}