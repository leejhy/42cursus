
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string name = "JUN";
	std::string target = "TAR";
	ScavTrap a(name);

	a.attack(target);
	std::cout << "Energy Left " << a.getEp() << " point\n";
	a.takeDamage(20);
	std::cout << "Energy Left " << a.getHp() << " point\n";
	a.guardGate();
}