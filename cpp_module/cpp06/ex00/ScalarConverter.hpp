
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>

class ScalarConverter//abstract class
{
    public :
        ScalarConverter();
        virtual ~ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator= (const ScalarConverter& obj);

        virtual void    abstract() = 0;
        static void     convert(std::string str);
};

#endif