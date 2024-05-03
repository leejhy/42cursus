
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("jun1", 1);
		Form		form1("form1", 20, 20);
		Bureaucrat	b("jun2", 11);
		Form		form2("form2", 10, 10);
		Form		tmp1("tmp1", 1, 1);
		std::cout << "===============================\n";
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << "===============================\n";
		std::cout << form1 << '\n';
		std::cout << form2 << '\n';
		std::cout << "===============================\n";

		a.signForm(form1);
		std::cout << form1 << '\n';
		std::cout << "===============================\n";

		b.signForm(form2);
		std::cout << form2 << '\n';
		std::cout << "===============================\n";
		b.incGrade();
		std::cout << b << '\n';
		b.signForm(form2);
		std::cout << form2 << '\n';
		std::cout << "===============================\n";
		std::cout << "hi end\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}