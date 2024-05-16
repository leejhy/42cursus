
#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "ARGUMENT ERROR\n";
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);
		rpn.print();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}