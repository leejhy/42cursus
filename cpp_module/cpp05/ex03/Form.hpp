
#ifndef Form_HPP
# define Form_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string	name;//Form name
		bool				check;//서명 여부 생성시 0
		const int			sign_grade;//내 Form에 서명하기 위한 등급
		const int			execute_grade;//내 Form 을 실행하기 위한 등급
		Form& operator=(Form const& obj);
	public :
		Form();
		virtual ~Form();
		Form(Form const& obj);

		Form(const std::string& name, const int s_grade, const int e_grade);
		void	beSigned(const Bureaucrat& obj);
		const std::string&	getName() const;
		bool				getCheck() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		virtual void execute (Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public :
				const char *what () const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what () const throw();
		};
		class FormIsNotSigned : public std::exception
		{
			public :
				const char *what () const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif