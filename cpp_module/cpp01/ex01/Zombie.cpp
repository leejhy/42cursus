
#include "Zombie.hpp"


void	Zombie::setName(std::string name){
	this->name = name;
}

Zombie::Zombie(void){
}

Zombie::~Zombie(void){
	std::cout << this->name << " is gone.." << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << " : " << "BraiiiiiiinnnzzzZ...\n";
}
