
#include "Form.hpp"
#include <iostream>

Form::Form()
: name("DEFAULT"), check(false), sign_grade(150), execute_grade(150){
	std::cout << this->name << " form Default constructor\n";
}
Form::Form(const std::string& name, const int s_grade, const int e_grade)
: name(name), check(0), sign_grade(s_grade), execute_grade(e_grade){
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
	else if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& obj)
: name(obj.name), check(obj.check), sign_grade(obj.sign_grade), execute_grade(obj.execute_grade){
	if (obj.sign_grade < 1 || obj.execute_grade < 1)
		throw GradeTooHighException();
	else if (obj.sign_grade > 150 || obj.execute_grade > 150)
		throw GradeTooLowException();	
	std::cout << "form copy\n";
}

Form::~Form(){
	std::cout << this->name << " form destructor\n";
}

Form& Form::operator=(Form const& obj) { (void)obj; return *this;}

void	Form::beSigned(const Bureaucrat& obj){
	int	b_grade;

	b_grade = obj.getGrade();
	if (b_grade <= this->sign_grade)//크거나 같으면 서명가능
		this->check = true;
	else
		throw GradeTooLowException();
}

const std::string&	Form::getName() const { return this->name; }
bool Form::getCheck() const { return this->check; }
int	Form::getSignGrade() const { return this->sign_grade; }
int	Form::getExecuteGrade() const { return this->execute_grade; }

std::ostream& operator<<(std::ostream& os, const Form& obj){
	os << "Form name : " << obj.getName() << " | "
	   << "Form check : " << obj.getCheck() << " | "
	   << "Form sign_grade : " << obj.getSignGrade() << " | "
	   << "Form execute_grade : " << obj.getExecuteGrade();
	return os;
}

const char *Form::GradeTooLowException::what() const throw(){
	return "*===Form EXCEPTION Grade Too Low===*";
}

const char *Form::GradeTooHighException::what() const throw(){
	return "*===Form EXCEPTION Grade Too High===*";
}