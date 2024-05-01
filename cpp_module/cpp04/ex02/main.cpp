#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

// void	f(){
// 	system("leaks ex02");
// }

int	main(void)
{
	// const Animal* meta = new Animal();//불가능 -> abstract class(추상클래스)이기 때문
	// 추상클래스의 인스턴스의 생성(오브젝트의 선언)은 컴파일러에서 허용하지 않음 
	const Animal* j = new Dog();//Upcast
	std::cout << "============================\n";
	const Animal* i = new Cat();
	std::cout << "============================\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! dog
	j->makeSound(); // cat
	std::cout << "============================\n";

	// atexit(f);
	delete i;
	delete j;
	return 0;
}
