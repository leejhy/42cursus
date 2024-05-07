#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string str;
	
	if (argc != 2){
		std::cout << "Argument error\n";
		return (1);
	}
	str = argv[1];//string으로 저장
	ScalarConverter::convert(str);
}