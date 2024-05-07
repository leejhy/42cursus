
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& obj){(void)obj;}

ScalarConverter&  ScalarConverter::operator= (const ScalarConverter& obj){(void)obj; return *this;}

void    ScalarConverter::convert(std::string str){
    char    a = static_cast<char>(std::stof(str));
    int     b = static_cast<int>(std::stof(str));
    float   c = static_cast<float>(std::stof(str));
    double  d = static_cast<double>(std::stof(str));

    if (!(32 <= a && a <= 126)){
        std::cout << "Non displayable\n";
    }
    else
        std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}