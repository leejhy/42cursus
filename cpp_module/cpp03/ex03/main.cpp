
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string name1 = "JUN_SCAV";
	std::string name2 = "JUN_FRAG";
	std::string target = "TARGET";
	ScavTrap scav(name1);
	std::cout << "=============================\n";
	FragTrap frag(name2);
	std::cout << "=============================\n";

	scav.attack(target);
	std::cout << "Energy Left " << scav.getEp() << " point\n";
	std::cout << "Energy Left " << scav.getHp() << " point\n";
	scav.takeDamage(20);
	std::cout << "Energy Left " << scav.getEp() << " point\n";
	std::cout << "Energy Left " << scav.getHp() << " point\n";
	scav.guardGate();
	std::cout << "=============================\n";
	frag.attack(target);
	std::cout << "Energy Left " << frag.getEp() << " point\n";
	std::cout << "Energy Left " << frag.getHp() << " point\n";
	frag.takeDamage(20);
	std::cout << "Energy Left " << frag.getEp() << " point\n";
	std::cout << "Energy Left " << frag.getHp() << " point\n";
	frag.highFivesGuys();
}