
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

// std::string const & getName() const;
// void equip(AMateria* m);
// void unequip(int idx);
// void use(int idx, ICharacter& target);

Character::Character(){
	//이상태에서 inventory 비어있고 ice, cure 넣을떄 new해서 넣기
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
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	// std::cout << "Character Destructor\n";
}

Character::Character(const Character& obj){
	//deep copy??
	(void)obj;
}

Character& Character::operator=(const Character& obj){
	(void)obj;
	return *this;
}

void	Character::equip(AMateria* m){
	int	i = 0;
	//m포인터로 받아온 값 character에 넣기
	while (this->inventory[i] != NULL)
		i++;
	if (i == 4)//꽉차있으면 아무것도 x
		return ;
	this->inventory[i] = m;//그냥 넣어도 되나?
}

void	Character::unequip(int idx){
//고민
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target){
	this->inventory[idx]->use(target);
}

std::string const & Character::getName() const{ return (this->name); }