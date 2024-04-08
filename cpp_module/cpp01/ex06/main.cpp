
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	str;

	if (argc != 2){
		std::cout << "Arguments error\n";
		return (1);
	}
	str = argv[1];
	if (str == "DEBUG")
		harl.complain(DEBUG);
	else if (str == "INFO")
		harl.complain(INFO);
	else if (str == "WARNING")
		harl.complain(WARNING);
	else if (str == "ERROR")
		harl.complain(ERROR);
	else
		harl.complain(ELSE);
}