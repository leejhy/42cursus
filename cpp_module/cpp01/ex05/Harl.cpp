
#include "Harl.hpp"

void	Harl::debug(void){
	std::cout << "Debugggggggggg" << std::endl;
}

void	Harl::info(void){
	std::cout << "Infofofoofoõ" << std::endl;
}

void	Harl::warning(void){
	std::cout << "WarWarningning" << std::endl;
}

void	Harl::error(void){
	std::cout << "errorrorororororororoooœœö" << std::endl;
}

void	Harl::complain(std::string level){
	std::string str[4];

	str[0] = "DEBUG";
	str[1] = "INFO";
	str[2] = "WARNING";
	str[3] = "ERROR";
	this->f[0] = &Harl::debug;
	this->f[1] = &Harl::info;
	this->f[2] = &Harl::warning;
	this->f[3] = &Harl::error;

	for (int i = 0; i < 4; i++){
		if (str[i] == level){
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "input error" << std::endl;
}