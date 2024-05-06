
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private :
		std::string target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name);

		void	makeTree() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif