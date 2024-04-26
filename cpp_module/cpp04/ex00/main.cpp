
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

// void f(){
// 	system("leaks ex00");
// }

int	main(void)
{
	const Animal* meta = new Animal();
	std::cout << "============================\n";
	const Animal* j = new Dog();//Upcast
	std::cout << "============================\n";
	const Animal* i = new Cat();
	std::cout << "============================\n";
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "============================\n";

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! dog
	j->makeSound(); // cat
	meta->makeSound(); // animal
	std::cout << "============================\n";

	std::cout << wrong_animal->getType() << std::endl;
	std::cout << wrong_cat->getType() << std::endl;
	wrong_animal->makeSound();
	wrong_cat->makeSound();
	std::cout << "============================\n";
	// atexit(f);
	delete meta;
	delete i;
	delete j;
	std::cout << "============================\n";
	delete wrong_animal;
	delete wrong_cat;
	return 0;
}
