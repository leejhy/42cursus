
#include "FragTrap.hpp"

FragTrap::FragTrap(){
	this->name = "NONAME";
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << this->name << " FragTrap default Constructor\n";
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name){
	this->name = name;
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30; 
	std::cout << this->name << " FragTrap string Constructor\n";
}

FragTrap::FragTrap(const FragTrap& fragtrap){
	*this = fragtrap;
	std::cout << this->name << " FragTrap Copy Constructor\n";
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap){
	this->name = fragtrap.name;
	this->hit_point = fragtrap.hit_point;
	this->energy_point = fragtrap.energy_point;
	this->attack_damage = fragtrap.attack_damage;
	std::cout << this->name << " FragTrap Copy assignment operator\n";
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << this->name << " FragTrap destructor\n";
}

void	FragTrap::highFivesGuys(void){
	std::cout << this->name << " FragTrap a positive high fives request\n";
}