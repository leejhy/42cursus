
#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;

	horde = zombieHorde(-1, "jun");
	delete [] horde;
}