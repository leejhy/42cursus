
#include "Zombie.hpp"

int	main(void)
{
	Zombie fir("hi");
	Zombie *sec;


	sec = newZombie("newnew");
	randomChump("randomChump");
	sec->announce();
	fir.announce();
	delete sec;
}