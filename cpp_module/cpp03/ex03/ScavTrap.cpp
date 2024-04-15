
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->name = "NONAME";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap default Constructor\n";
}

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name){
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap string Constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap){
	std::cout << this->name << " ScavTrap Copy Constructor\n";
	*this = scavtrap;
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

void ScavTrap::guardGate(){
	std::cout << this->name << " ScavTrap is now in Gate keeper mode\n";
}