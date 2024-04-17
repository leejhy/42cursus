
#include "Animal.hpp"
#include <iostream>

Animal::Animal(){
	std::cout << "Animal default constuctor\n";
}

Animal::Animal(const Animal& animal){
	this->type = animal.type;
	std::cout << "Animal copy constructor\n";
}

Animal& Animal::operator=(const Animal& animal){
	this->type = animal.type;
	std::cout << "Animal copy assignment operator\n";
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor\n";
}

void	Animal::makeSound(){
	std::cout << "Animal Sound\n";
}

const std::string&	Animal::getType(){
	return (this->type);
}