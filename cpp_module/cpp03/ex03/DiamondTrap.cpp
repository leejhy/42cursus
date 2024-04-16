
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	this->name = "NONAME";
	ClapTrap::name = this->name + "_clap_name";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 30;
	std::cout << this->name << " DiamondTrap Default Constructor\n";
}

DiamondTrap::DiamondTrap(std::string name){
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 30;
	std::cout << this->name << " DiamondTrap name Constructor\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
: ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap){
	this->name = diamondtrap.name;
	ClapTrap::name = this->name + "_clap_name";
	this->hit_point = diamondtrap.hit_point;
	this->energy_point = diamondtrap.energy_point;
	this->attack_damage = diamondtrap.attack_damage;
	std::cout << this->name << " DiamondTrap Copy Constructor\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap){
	this->name = diamondtrap.name;
	ClapTrap::name = this->name + "_clap_name";
	this->hit_point = diamondtrap.hit_point;
	this->energy_point = diamondtrap.energy_point;
	this->attack_damage = diamondtrap.attack_damage;
	std::cout << this->name << " DiamondTrap Copy assignment\n";
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << this->name << " DiamondTrap destructor\n";
}

void	DiamondTrap::whoAmI(){
	std::cout << "who AM I?\n";
	std::cout << "clapTrap's name : " << ClapTrap::name << std::endl;
	std::cout << "diaTrap's name : " << this->name << std::endl;
}