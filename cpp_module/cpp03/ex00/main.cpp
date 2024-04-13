
#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string target = "TARGET";
	std::string name = "JUNHYLEE";
	ClapTrap a;
	ClapTrap b(name);

	std::cout	<< "name : " << a.getName() << ' '
				<< "Hp : " << a.getHp() << ' ' 
				<< "Energy : " << a.getEp() << ' ' 
				<< "Damage : " << a.getDamage() << ' ' << std::endl;
	std::cout	<< "name : " << b.getName() << ' '
				<< "Hp : " << b.getHp() << ' ' 
				<< "Energy : " << b.getEp() << ' ' 
				<< "Damage : " << b.getDamage() << ' ' << std::endl;
	std::cout << "============================================\n";
	b.attack(target);
	std::cout << "HP Left " << b.getHp() << " point\n";
	std::cout << "Energy Left " << b.getEp() << " point\n";
	std::cout << "============================================\n";
	b.beRepaired(10);
	std::cout << "HP Left " << b.getHp() << " point\n";
	std::cout << "Energy Left " << b.getEp() << " point\n";
	std::cout << "============================================\n";
	b.takeDamage(20);
	std::cout << "HP Left " << b.getHp() << " point\n";
	std::cout << "Energy Left " << b.getEp() << " point\n";
	std::cout << "============================================\n";
	b.attack(target);
	b.beRepaired(10);
	b.takeDamage(10);
	std::cout << "HP Left " << b.getHp() << " point\n";
	std::cout << "Energy Left " << b.getEp() << " point\n";
}