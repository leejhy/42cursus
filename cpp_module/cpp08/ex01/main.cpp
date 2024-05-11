
#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(10);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int> tvec(10000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.print();
	std::cout << "==================\n";
	sp.addNumberRange(tvec.begin(), tvec.end(), 500);
	std::cout << sp.getSize() <<std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}