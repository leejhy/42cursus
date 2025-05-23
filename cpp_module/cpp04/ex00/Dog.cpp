#include "Dog.hpp"
#include <iostream>

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog default constuctor\n";
}

Dog::Dog(const Dog& dog) : Animal(dog){
	this->type = dog.type;
	std::cout << "Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& dog){
	this->type = dog.type;
	std::cout << "Dog copy assignment operator\n";
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor\n";
}

void	Dog::makeSound() const{
	std::cout << "Doododododododdoodooogggg\n";
}