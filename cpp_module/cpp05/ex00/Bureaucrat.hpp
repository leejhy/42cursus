
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private :
		std::string const&	name;
		unsigned int		grade;
	public :
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);

		void GradeTooHighException();
		void GradeTooLowException();
		std::string const& getName();
		unsigned int getGrade();
};

#endif