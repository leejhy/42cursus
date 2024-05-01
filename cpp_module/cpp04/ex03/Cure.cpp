
#include "Cure.hpp"
#include <iostream>

Cure::Cure(){
	this->type = "cure";
	// std::cout << "Cure Constructor\n";
}

Cure::~Cure(){
	// std::cout << "Cure Destuctor\n";
}

Cure::Cure(const Cure& obj){
	this->type = obj.type;
	// std::cout << "Cure copy\n";
}

Cure& Cure::operator=(const Cure& obj){
	this->type = obj.type;
	// std::cout << "Cure copy assignment\n";
	return (*this);
}

Cure* Cure::clone() const{
	Cure *tmp;

	tmp = new Cure();
	return (tmp);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}
