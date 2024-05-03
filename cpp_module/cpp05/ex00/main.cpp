
#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("jun1", 3);

		std::cout << a << '\n';//3
		a.decGrade();
		std::cout << a << '\n';//4
		a.decGrade();
		a.decGrade();
		std::cout << a << '\n';//6
		a.incGrade();
		a.incGrade();
		std::cout << a << '\n';//4
		a.incGrade();
		std::cout << a << '\n';//3
		a.incGrade();
		a.incGrade();
		// a.incGrade();//이거 여는 순간 throw
		std::cout << a << '\n';//1

		// Bureaucrat b("jun2", 150);
		// std::cout << b << '\n';
		// b.decGrade();
		// std::cout << b << '\n';
		std::cout << "hi end\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}