
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->name = "NONAME";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap default Constructor\n";
}

ScavTrap::ScavTrap(std::string name){
	this->name = name;
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap string Constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap){
	this->name = scavtrap.name;
	this->hit_point = scavtrap.hit_point;
	this->energy_point = scavtrap.energy_point;
	this->attack_damage = scavtrap.attack_damage;
	std::cout << this->name << " ScavTrap Copy Constructor\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap){
	this->name = scavtrap.name;
	this->hit_point = scavtrap.hit_point;
	this->energy_point = scavtrap.energy_point;
	this->attack_damage = scavtrap.attack_damage;
	std::cout << this->name << " ScavTrap Copy assignment operator\n";
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << this->name << " ScavTrap Destructor\n";
}

void	ScavTrap::guardGate(){
	if (this->energy_point == 0 || this->hit_point == 0){
		std::cout << this->name << " ScavTrap can't do anything\n";
		return ;
	}
	std::cout << this->name << " ScavTrap is now in Gate keeper mode\n";
}

void	ScavTrap::attack(const std::string& target){
	if (this->energy_point == 0 || this->hit_point == 0){
		std::cout << this->name << " ScavTrap can't do anything\n";
		return ;
	}
	this->energy_point--;
	std::cout << "ScavTrap " << this->name << " attacks " << target \
	<< ", causing " << this->attack_damage << " points of damage!\n" ;
}