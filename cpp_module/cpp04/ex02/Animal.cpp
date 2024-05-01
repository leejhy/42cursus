
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

// void	Animal::makeSound() const {//있든없든 상관x
// 	std::cout << "Animal Sound\n";
// }

const std::string&	Animal::getType() const{
	return (this->type);
}