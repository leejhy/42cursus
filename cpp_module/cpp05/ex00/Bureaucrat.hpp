
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private :
		std::string const	name;
		int					grade;
		Bureaucrat& operator=(const Bureaucrat& obj);//금지
	public :
		Bureaucrat();
		Bureaucrat(std::string const& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);

		const std::string&	getName() const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();
		class GradeTooHighException : public std::exception
		{
			public :
				const char *what () const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what () const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif