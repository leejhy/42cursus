#include "Dog.hpp"
#include <iostream>

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog default constuctor\n";
	this->brain = new Brain();
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
	delete this->brain;
	std::cout << "Dog destructor\n";
}

void	Dog::makeSound() const{
	std::cout << "Doododododododdoodooogggg\n";
	this->brain->getIdeas(15);
}
