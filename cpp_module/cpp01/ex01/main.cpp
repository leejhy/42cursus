
#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;

	horde = zombieHorde(5, "jun");
	delete [] horde;
}