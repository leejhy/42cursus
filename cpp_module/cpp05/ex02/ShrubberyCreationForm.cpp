
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: AForm(obj){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{(void)obj; return *this;}

ShrubberyCreationForm::ShrubberyCreationForm\
(const std::string& name)
: AForm(name, 145, 137){
	this->target = name;
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& obj){(void)obj;}

void	ShrubberyCreationForm::makeTree(){
	std::ofstream ofs;
	std::string	filename;

	filename = this->target + "_shrubbery";
	std::cout << filename << '\n';
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