
#include "Zombie.hpp"


void	Zombie::setName(std::string name){
	this->name = name;
}

Zombie::~Zombie(void){
	std::cout << name << " is gone.." << std::endl;
}

void	Zombie::announce(void){
	std::cout << name << " : " << "BraiiiiiiinnnzzzZ...\n";
}
