
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		// Bureaucrat				a("asd", 151);
		// Bureaucrat				a("asd", 0);
		Bureaucrat				jun1("jun1", 140);
		Bureaucrat				jun2("jun2", 60);
		Bureaucrat				jun3("jun3", 20);
		Bureaucrat				jun4("jun4", 1);
		std::cout << "=================\n";
		ShrubberyCreationForm shu1("shruu1");
		RobotomyRequestForm robo1("Robobo1");
		PresidentialPardonForm presi1("Presii1");
		ShrubberyCreationForm shu2("shruu2");
		RobotomyRequestForm robo2("Robobo2");
		PresidentialPardonForm presi2("Presii2");
		ShrubberyCreationForm shu3("shruu3");
		RobotomyRequestForm robo3("Robobo3");
		PresidentialPardonForm presi3("Presii3");
		ShrubberyCreationForm shu4("shruu4");
		RobotomyRequestForm robo4("Robobo4");
		PresidentialPardonForm presi4("Presii4");

		std::cout << shu1 << std::endl;
		std::cout << robo1 << std::endl;
		std::cout << presi1 << std::endl;
		std::cout << "\n=================\n";
		try
		{//jun1 grade 140
			jun1.signForm(shu1);//145 뒤집어서 한번
			jun1.executeForm(shu1);//137
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n====================\n\n";
		try
		{//jun2 grade 60
			jun2.signForm(shu2);//145
			jun2.executeForm(shu2);//137
			jun2.signForm(robo2);//72
			jun2.executeForm(robo2);//45
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n====================\n\n";
		try
		{//jun3 grade 20
			jun3.signForm(shu3);//145
			jun3.executeForm(shu3);//137
			jun3.signForm(robo3);//72
			jun3.executeForm(robo3);//45
			jun3.signForm(presi3);//25
			jun3.executeForm(presi3);//5
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n====================\n";
		try
		{//jun4 grade 1
			jun4.signForm(shu4);//145
			jun4.executeForm(shu4);//137
			jun4.signForm(robo4);//72
			jun4.executeForm(robo4);//45
			jun4.signForm(presi4);//25
			jun4.executeForm(presi4);//5
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n\nhi end!\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}