
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("DEFAULT"), grade(150){
	std::cout << this->name << " Constructor\n";
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
: name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << this->name << " Constructor\n";
}

Bureaucrat::~Bureaucrat(){
	std::cout << this->name << " Destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
: name(obj.name), grade(obj.grade){
	std::cout << "Copy constructor\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){(void)obj; return *this;}

const std::string& Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void	Bureaucrat::incGrade(){
	long tmp;

	tmp = this->grade - 1;
	if (tmp < 1) //highest
		throw Bureaucrat::GradeTooHighException();//예외
	this->grade -= 1;
}

void	Bureaucrat::decGrade(){
	long tmp;

	tmp = this->grade + 1;
	if (tmp > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what () const throw (){
	return "*===Bureaucrat EXCEPTION Grade Too High===*";
}

const char *Bureaucrat::GradeTooLowException::what () const throw (){
	return "*===Bureaucrat EXCEPTION Grade Too Low===*";
}

void	Bureaucrat::signForm(AForm& form){
	if (this->grade > form.getSignGrade()){
		std::cout << this->name << " couldn't sign " << form.getName() << " because grade too low\n";
		return ;
	}
	else{//this->grade <= form grade
		form.beSigned(*this);//가능?
		std::cout << this->name << " signed " << form.getName() << '\n';
		return ;
	}
}//새로 추가