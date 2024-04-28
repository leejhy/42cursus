
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "WrongCat default constuctor\n";
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat){
	this->type = wrongcat.type;
	std::cout << "WrongCat copy constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat){
	this->type = wrongcat.type;
	std::cout << "WrongCat copy assignment operator\n";
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor\n";
}

void	WrongCat::makeSound() const{
	std::cout << "wrorrorororongcaccacaccacacacacacactttt\n";
}