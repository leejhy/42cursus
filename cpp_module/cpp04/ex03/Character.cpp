
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

Character::Character(){
	// std::cout << "Character default Constructor\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const std::string& name){
	this->name = name;
	// std::cout << "Character name Constructor\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] != NULL){
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	// std::cout << "Character Destructor\n";
}

Character::Character(const Character& obj){
	for (int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
		if (obj.inventory[i] != NULL)
			this->inventory[i] = obj.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& obj){
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
		if (obj.inventory[i] != NULL)
			this->inventory[i] = obj.inventory[i]->clone();
	}
	return *this;
}

void	Character::equip(AMateria* m){
	int	i;

	for (i = 0; i < 4; i++){
		if (this->inventory[i] == NULL)
			break ;
	}
	if (i == 4)//꽉차있으면 아무것도 x
		return ;
	this->inventory[i] = m;
}

void	Character::unequip(int idx){
	if (idx < 0 || idx >= 4)
		return ;
	if (this->inventory[idx] == NULL){
		std::cout << this->name << " get nothing\n";
		return ;
	}
	// std::cout << this->name << " unequip " << this->inventory[idx]->getType() << '\n';
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >= 4)
		return ;
	if (this->inventory[idx] == NULL){
		std::cout << this->name << " get nothing skill\n";
		return ;
	}
	this->inventory[idx]->use(target);
}

std::string const & Character::getName() const{ return (this->name); }
