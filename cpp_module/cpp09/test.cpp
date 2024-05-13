
#include <iostream>

int	main(void)
{
	std::string str = "12.12313313";
	std::string str1 = "1234...12313313";
	std::string str2 = "5112.1-2313313";
	std::string str3 = "--412.12313313";
	std::string str4 = "0";

	std::cout << std::atof(str.c_str()) << std::endl;
	std::cout << std::atof(str1.c_str()) << std::endl;
	std::cout << std::atof(str2.c_str()) << std::endl;
	std::cout << std::atof(str3.c_str()) << std::endl;
	std::cout << std::atof(str4.c_str()) << std::endl;
}