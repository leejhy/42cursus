
#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	try
	{
		BitcoinExchange Bit(argv[1]);
		Bit.openDatabase();
		Bit.inputData();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}