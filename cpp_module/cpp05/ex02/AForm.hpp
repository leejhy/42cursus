
#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string	name;//Aform name
		bool				check;//서명 여부 생성시 0
		const int			sign_grade;//내 Aform에 서명하기 위한 등급
		const int			execute_grade;//내 Aform 을 실행하기 위한 등급
		AForm& operator=(AForm const& obj);
	public :
		AForm();
		virtual ~AForm();
		AForm(AForm const& obj);

		AForm(const std::string& name, const int s_grade, const int e_grade);
		virtual void	beSigned(const Bureaucrat& obj) = 0;//
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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif