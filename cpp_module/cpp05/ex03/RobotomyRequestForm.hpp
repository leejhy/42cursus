
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private :
		std::string target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name);
		void	robotomize() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif
