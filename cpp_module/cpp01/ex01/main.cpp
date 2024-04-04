
#include "Zombie.hpp"

void	f(){
	system("leaks ex01");
}

int	main(void)
{
	Zombie *horde;

	horde = zombieHorde(5, "jun");
	delete [] horde;
}