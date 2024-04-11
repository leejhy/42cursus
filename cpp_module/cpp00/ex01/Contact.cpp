
#include "Contact.hpp"

void	Contact::printContact(int index){
	int	tmp;
	int	len;
	
	len = 0;
	tmp = index;
	while (tmp){
		tmp /= 10;
		len++;
	}
	std::cout << "index : ";
	for (int i = 0; i < 10 - len - 1; i++)
		std::cout << ' ';
	if (index != 0)
		std::cout << ' ';
	std::cout << index << " | ";

	std::cout << "first name : ";
	printElement(first_name);

	std::cout << "last name : ";
	printElement(last_name);

	std::cout << "nick name : ";
	printElement(nick_name);
	std::cout << std::endl;
}

void	Contact::printElement(std::string str){
	if (str.length() > 10){
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ". | ";
	}
	else
		std::cout << str << " | ";
}

void	Contact::AddContact(){

	std::cout << "first name : ";
	first_name = AddElement();

	std::cout << "last name : ";
	last_name = AddElement();

	std::cout << "nick name : ";
	nick_name = AddElement();

	std::cout << "phone number : ";
	phone_number = AddElement();

	std::cout << "darkest secret : ";
	darkest_secret = AddElement();
}

std::string	Contact::AddElement(){
	std::string input;
	int			input_len;

	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "EOF" << std::endl;
		clearerr(stdin);
		std::cin.clear();
		return ("EOF");
	}
	input_len = input.length();
	if (input_len < 10){
		for (int i = 0; i < 10 - input_len; i++)
			input.insert(0, " ");
	}
	return (input);
}