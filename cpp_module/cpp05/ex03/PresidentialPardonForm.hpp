
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private :
		std::string target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name);

		void	inForm() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif
