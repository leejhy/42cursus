
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	if (N < 0)
		return NULL;
	Zombie *tmp = new Zombie[N];
	std::stringstream ss;

	for (int i = 0; i < N; i++){
		ss.str("");
		ss << i;
		tmp[i].setName(name + ss.str());
		tmp[i].announce();
	}
	return (tmp);
}