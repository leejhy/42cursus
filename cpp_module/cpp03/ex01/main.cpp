
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string name = "JUN";
	std::string target = "TAR";
	ScavTrap scav(name);

	scav.attack(target);
	std::cout << "Energy Left " << scav.getEp() << " point\n";
	scav.takeDamage(20);
	std::cout << "Energy Left " << scav.getHp() << " point\n";
	scav.guardGate();
}