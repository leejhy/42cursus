
#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	try
	{
		BitcoinExchange Bit(argv[1]);
	}
	catch (std::exception& e)
	{

	}
}