
#include "PhoneBook.hpp"

void	PhoneBook::init(){
	idx = 0;
}

void	PhoneBook::Add(){
	contact[idx % 8].AddContact();
	std::cout << "Added the " << idx % 8 << "th idx\n";
	idx++;
}

void	PhoneBook::Search(){
	long	input;

	std::cout << "put the index you want to find : ";
	std::cin >> input;
	if (std::cin.eof())
	{
		std::cout << "EOF" << std::endl;
		clearerr(stdin);
		std::cin.clear();
		return ;
	}
	if (idx - 1 < input || !(0 <= input && input < 8)){
		std::cout << "Wrong index, move the first prompt .\n";
		return ;
	}
	contact[input % 8].printContact(input % 8);
}