
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& obj){(void)obj;}

ScalarConverter&  ScalarConverter::operator= (const ScalarConverter& obj){(void)obj; return *this;}

void    ScalarConverter::convert(std::string str){
	double	stof = static_cast<float>(atof(str.c_str()));
    char    a = static_cast<char>(atof(str.c_str()));
    long    b = atol(str.c_str());
    float   c = static_cast<float>(atof(str.c_str()));
    double  d = static_cast<double>(atof(str.c_str()));

	if (isnan(stof)){//stof!=stof // nan은 자기자신과도 false
		std::cout << "char: impossible\n"; 
		std::cout << "int: impossible\n"; 
		std::cout << "float: nanf\n"; 
		std::cout << "double: nan\n"; 
		return ;
	}

    if (!(32 <= a && a <= 126))
        std::cout << "char: Non displayable\n";
	else
    	std::cout << "char: " << '\'' << a << '\'' << std::endl;

	if (b > INT_MAX)
		std::cout << "int: can not type casting\n";
	else if (b < INT_MIN)
		std::cout << "int: can not type casting\n";
	else
    	std::cout << "int: " << static_cast<int>(b) << std::endl;

    std::cout << "float: ";
	if (isinf(c)){
		if (c > 0)
			std::cout << "inff\n";
		else
			std::cout << "-inff\n";
	}
	else{
		std::cout << c;
		if (c == floorf(c))
			std::cout << ".0f\n";
		else
			std::cout << "f\n";
	}
    std::cout << "double: ";
	if (isinf(d)){
		if (d > 0)
			std::cout << "inff\n";
		else
			std::cout << "-inff\n";
	}
	else{
		std::cout << d;
		if (d == floor(d))
			std::cout << ".0\n";
		else
			std::cout << '\n';
	}
}