
#include "Cat.hpp"
#include <iostream>

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat default constuctor\n";
}

Cat::Cat(const Cat& cat) : Animal(cat){
	this->type = cat.type;
	std::cout << "Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& cat){
	this->type = cat.type;
	std::cout << "Cat copy assignment operator\n";
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor\n";
}

void	Cat::makeSound() const{
	std::cout << "Cacacacacacacactttt\n";
}