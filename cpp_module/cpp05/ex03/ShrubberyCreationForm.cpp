
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form(){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: Form(obj){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{(void)obj; return *this;}

ShrubberyCreationForm::ShrubberyCreationForm\
(const std::string& target)
: Form(target+"_name", 145, 137){
	this->target = target;
}

void	ShrubberyCreationForm::makeTree() const{
	std::ofstream ofs;
	std::string	filename;

	filename = this->target + "_shrubbery";
	ofs.open(filename.c_str());

	ofs << "	ccee88oo \n";
	ofs << "  C8O8O8Q8PoOb o8oo \n";
	ofs << " dOB69QO8PdUOpugoO9bD \n";
	ofs << "CgggbU8OU qOp qOdoUOdcb \n";
	ofs << "    6OuU  /p u gcoUodpP \n";
	ofs << "      \\\\\\//  /douUP \n";
	ofs << "        \\\\\\//// \n";
	ofs << "         |||/\\ \n";
	ofs << "         |||\\/ \n";
	ofs << "         ||||| \n";
	ofs << "   .....//||||\\.... ";
	ofs.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	//서명되었는지 확인하고, 등급확인하고 throw
	if (!this->getCheck())
		throw FormIsNotSigned();
	if (this->getExecuteGrade() < executor.getGrade())//executor가 더 크면 등급이 낮음, 같으면 실행가능
		throw GradeTooLowException();
	this->makeTree();
}
