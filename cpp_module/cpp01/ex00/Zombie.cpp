
#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << name << " Zombie is created" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << this->name << " is gone.." << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << " : " << "BraiiiiiiinnnzzzZ...\n";
}
