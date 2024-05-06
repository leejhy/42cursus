
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// void	f()
// {
// 	system("leaks ex03");
// }

int	main(void)
{
	Bureaucrat	jun1("jun1", 40);
	Intern		intern;
	Form*		a;
	Form*		b;
	Form*		c;
	// Form*		d;
	try
	{
		a = intern.makeForm("shrubbery creation", "shu123");
		b = intern.makeForm("robotomy request", "robo123");
		c = intern.makeForm("presidential pardon", "pres123");
		// d = intern.makeForm("err", "errr");
		std::cout << "================\n";
		jun1.signForm(*a);
		jun1.executeForm(*a);
		std::cout << "================\n";
		jun1.signForm(*b);
		jun1.executeForm(*b);
		std::cout << "================\n";
		jun1.signForm(*c);
		jun1.executeForm(*c);
		std::cout << "=hi end\n";
		delete a;
		delete b;
		delete c;
	}
	catch (std::exception &e)
	{
		delete a;
		delete b;
		delete c;
		std::cout << e.what() << std::endl;
	}
	// atexit(f);
}