
#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public :
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);

		Form* makeShu(std::string target);
		Form* makePres(std::string target);
		Form* makerobo(std::string target);
		Form* makeForm(const std::string& name, const std::string& target);

		class IsNotExist : public std::exception
		{
			public :
				const char *what () const throw ();
		};
};

#endif