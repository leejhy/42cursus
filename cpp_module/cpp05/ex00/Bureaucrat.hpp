
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private :
		std::string const&	name;
		int					grade;
	public :
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string&	getName() const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();
		void	GradeTooHighException();
		void	GradeTooLowException();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif