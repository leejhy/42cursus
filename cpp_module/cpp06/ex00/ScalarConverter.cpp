
#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& obj){(void)obj;}

ScalarConverter&  ScalarConverter::operator= (const ScalarConverter& obj){(void)obj; return *this;}

void    ScalarConverter::convert(std::string str){
    char    a;
    int     b;
    float   c;
    double  d;

    if (!(32 <= c && c <= 126)){
        std::cout << "Non printable character\n";
        return ;
    }
    a = static_cast<char>(str);
	b = static_cast<int>(str);
	c = static_cast<float>(str);
	d = static_cast<double>(str);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}