
#include "Harl.hpp"

void	Harl::debug(void){
	std::cout << "[ DEBUG ]\n";
	std::cout << "Deeeêębugggggggggg\n" << std::endl;
}

void	Harl::info(void){
	std::cout << "[ INFO ]\n";
	std::cout << "Infofofoofoõ\n" << std::endl;
}

void	Harl::warning(void){
	std::cout << "[ WARNING ]\n";
	std::cout << "WarWarningninggg\n" << std::endl;
}

void	Harl::error(void){
	std::cout << "[ ERROR ]\n";
	std::cout << "errorrorororororororoooœœö\n" << std::endl;
}

void	Harl::complain(int level){
	this->f[0] = &Harl::debug;
	this->f[1] = &Harl::info;
	this->f[2] = &Harl::warning;
	this->f[3] = &Harl::error;

	switch (level){
		case DEBUG :
			(this->*f[0])();
		case INFO :
			(this->*f[1])();
		case WARNING :
			(this->*f[2])();
		case ERROR :
			(this->*f[3])();
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}