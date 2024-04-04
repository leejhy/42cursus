
#include "Zombie.hpp"

void	randomChump(std::string name){
	Zombie tmp(name);//매개변수 있는 인스턴스
	tmp.announce();
}