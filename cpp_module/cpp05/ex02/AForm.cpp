
#include "AForm.hpp"
#include <iostream>

AForm::AForm()
: name("DEFAULT"), check(false), sign_grade(150), execute_grade(150){
	std::cout << this->name << " Aform Default constructor\n";
}
AForm::AForm(const std::string& name, const int s_grade, const int e_grade)
: name(name), check(0), sign_grade(s_grade), execute_grade(e_grade){
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
	else if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& obj)
: name(obj.name), check(obj.check), sign_grade(obj.sign_grade), execute_grade(obj.execute_grade){
	if (obj.sign_grade < 1 || obj.execute_grade < 1)
		throw GradeTooHighException();
	else if (obj.sign_grade > 150 || obj.execute_grade > 150)
		throw GradeTooLowException();	
	std::cout << "Aform copy\n";
}

AForm::~AForm(){
	std::cout << this->name << " Aform destructor\n";
}

AForm& AForm::operator=(AForm const& obj) { (void)obj; return *this;}

void	AForm::beSigned(const Bureaucrat& obj){
	int	b_grade;

	b_grade = obj.getGrade();
	if (b_grade <= this->sign_grade)//크거나 같으면 서명가능
		this->check = true;
	else
		throw GradeTooLowException();
}

const std::string&	AForm::getName() const { return this->name; }
bool AForm::getCheck() const { return this->check; }
int	AForm::getSignGrade() const { return this->sign_grade; }
int	AForm::getExecuteGrade() const { return this->execute_grade; }

std::ostream& operator<<(std::ostream& os, const AForm& obj){
	os << "AForm name : " << obj.getName() << " | "
	   << "AForm check : " << obj.getCheck() << " | "
	   << "AForm sign_grade : " << obj.getSignGrade() << " | "
	   << "AForm execute_grade : " << obj.getExecuteGrade();
	return os;
}

const char *AForm::GradeTooLowException::what() const throw(){
	return "*===AForm EXCEPTION Grade Too Low===*";
}

const char *AForm::GradeTooHighException::what() const throw(){
	return "*===AForm EXCEPTION Grade Too High===*";
}