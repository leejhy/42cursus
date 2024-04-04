
#include "HumanB.hpp"

void	HumanB::attack(){
	std::cout << name << " attacks with their " 
			  << weapon.getType() << std::endl;
}