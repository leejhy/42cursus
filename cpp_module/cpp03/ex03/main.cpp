
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap	frag;
	std::cout << "==========================\n";
	ScavTrap	scav;
	std::cout << "==========================\n";
	DiamondTrap dia("JUNHYLEE");
	std::cout << "==========================\n";

	std::cout << "frag HP " << frag.getHp() << std::endl;
	std::cout << "dia HP " << dia.getHp() << std::endl;
	std::cout << "scav EP " << scav.getEp() << std::endl;
	std::cout << "dia EP " << dia.getEp() << std::endl;
	std::cout << "frag EP " << frag.getDamage() << std::endl;
	std::cout << "dia EP " << dia.getDamage() << std::endl;
	std::cout << "==========================\n";
	dia.attack("TARGET");
	std::cout << "==========================\n";
	dia.whoAmI();
}