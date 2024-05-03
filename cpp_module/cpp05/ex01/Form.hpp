
#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string	name;//form name
		bool				check;//서명 여부 생성시 0
		const int			sign_grade;//내 form에 서명하기 위한 등급
		const int			execute_grade;//내 form 을 실행하기 위한 등급
		Form& operator=(Form const& obj);
	public :
		Form();
		~Form();
		Form(Form const& obj);

		Form(const std::string& name, const int s_grade, const int e_grade);
		void	beSigned(const Bureaucrat& obj);//
		const std::string&	getName() const;
		bool				getCheck() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif