
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal default constuctor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal){
	this->type = wronganimal.type;
	std::cout << "WrongAnimal copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal){
	this->type = wronganimal.type;
	std::cout << "WrongAnimal copy assignment operator\n";
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor\n";
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAniWrongAniWrongAniWrongAniWrongAniWrongAniWrongAniWrongAniWrongAniWrongAniWrongAnimal Sound\n";
}

const std::string&	WrongAnimal::getType() const{
	return (this->type);
}