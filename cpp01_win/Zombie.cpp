
#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << name << " Zombie is created" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << name << " is gone.." << std::endl;
}

void	Zombie::announce(void){
	std::cout << name << " : " << "BraiiiiiiinnnzzzZ...\n";
}

Zombie*	newZombie(std::string name){
	Zombie *tmp = new Zombie(name);
	return (tmp);
}

void	randomChump(std::string name){
	Zombie tmp(name);//매개변수 있는 인스턴스
	tmp.announce();
}