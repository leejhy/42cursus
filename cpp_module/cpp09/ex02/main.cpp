
#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1){
		std::cout << "NO ARGUMENT\n";
		return 1;
	}
	try
	{
		PmergeMe Sort(argc, argv);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
// ./PmergeMe 19 5 3 8 4 15 28 30 7 29 10 2 31 6 14 24 1 25 9 17 26 18 20 12 27 16 13 21 23 22 11 -> ok
// ./PmergeMe 19 5 3 8 4 15 28 30 7 29 10 2 31 6 14 24 1 25 9 17 26 18 20 12 27 16 13 21 23 22 -> x
// ./PmergeMe 19 5 3 8 4 15 28 30 7 29 10 2 31 6 14 24 1 25 9 17 26 18 20 12 27 16 13 21 -> x
// ./PmergeMe 19 5 3 8 4 15 28 30 7 29 10 2 31 6 14 24 1 25 9 17 26 18 20 12 27 16 -> x