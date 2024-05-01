
#include "Ice.hpp"
#include <iostream>

Ice::Ice(){
	this->type = "ice";
	std::cout << "Ice Constructor\n";
}

Ice::~Ice(){
	std::cout << "Ice Destructor\n";
}

Ice::Ice(const Ice& obj){
	this->type = obj.type;
	std::cout << "Ice Copy\n";
}

Ice& Ice::operator=(const Ice& obj){
	this->type = obj.type;
	std::cout << "Ice copy assignment\n";
}

Ice* Ice::clone() const{
	Ice *tmp;

	tmp = new Ice();
	return (tmp);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
