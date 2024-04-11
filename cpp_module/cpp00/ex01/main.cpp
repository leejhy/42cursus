
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	phone_book.init();
	while (1)
	{
		std::cout << "input ADD or SEARCH or EXIT \n";
		std::cout << "input : ";
		std::cin >> input;
		if (input == "ADD"){
			phone_book.Add();
		}
		else if (input == "SEARCH"){
			phone_book.Search();
		}
		else if (input == "EXIT"){
			std::cout << "EXIT" << std::endl;
			return (0);
		}
		else if (std::cin.eof())
		{
			std::cout << "EOF" << std::endl;
			clearerr(stdin);
			std::cin.clear();
			return (0);
		}
		else{
			std::cout << "Wrong input, try again\n";
		}
	}
}