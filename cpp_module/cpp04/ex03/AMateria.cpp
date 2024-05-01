
#include "AMateria.hpp"
#include <iostream>
// protected :
// 	std::string type;
// public :
// 	virtual void use(ICharacter& target);

AMateria::AMateria(){
	std::cout << "AMateria Constructor\n";
}

AMateria::AMateria(const AMateria& obj){
	this->type = obj.type;
	std::cout << "AMateria Copy\n";
}

AMateria& AMateria::operator=(const AMateria& obj){
	this->type = obj.type;
	std::cout << "AMateria Copy assignment\n";
	return (*this);
}

AMateria::AMateria(std::string const& type){
	this->type = type;
	std::cout << "AMateria type Constructor\n";
}

std::string const& AMateria::getType() const{ return (this->type); }


AMateria::~AMateria(){
	std::cout << "AMateria Destructor\n";
}

void AMateria::use(ICharacter& target){
	// std::cout << target.getName();
}