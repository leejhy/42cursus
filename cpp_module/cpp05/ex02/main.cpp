
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	ShrubberyCreationForm shu("shruu");
	RobotomyRequestForm Robo("Robobo");

	std::cout << shu << std::endl;
	std::cout << Robo << std::endl;
	shu.makeTree();
	Robo.robotomize();
}