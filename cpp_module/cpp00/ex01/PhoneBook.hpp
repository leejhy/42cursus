
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook{
	private :
		int		idx;
		Contact	contact[8];
	public :
		void	init();
		void	Add();
		void	Search();
};

#endif