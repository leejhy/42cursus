
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{
	private :
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public :
		void		printContact(int index);
		void		printElement(std::string str);
		void		AddContact();
		std::string	AddElement();
		
};

#endif