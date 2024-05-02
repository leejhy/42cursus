#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

// void	f(){
// 	system("leaks ex01");
// }

int main()
{
	const Animal* j = new Dog();
	std::cout << "================\n";
	const Animal* i = new Cat();
	std::cout << "================\n";
	const Animal*	animal[4];

	animal[0] = new Dog();
	animal[1] = new Dog();
	animal[2] = new Cat();
	animal[3] = new Cat();
	std::cout << "================\n";

	animal[0]->makeSound();
	animal[1]->makeSound();
	animal[2]->makeSound();
	animal[3]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animal[i];
	std::cout << "================\n";
	delete j;//should not create a leak
	delete i;
	// atexit(f);
	return 0;
}