
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name("NONAME"), hit_point(10), energy_point(10), attack_damage(0){
	std::cout << this->name << " ClapTrap Default Constructor\n";
}

ClapTrap::ClapTrap(std::string name)
: name(name), hit_point(10), energy_point(10), attack_damage(0){
	std::cout << this->name << " ClapTrap string Constructor\n";
}

ClapTrap::ClapTrap(const ClapTrap& claptrap){
	std::cout << this->name << " ClapTrap Copy Constructor\n";
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap){
	std::cout << this->name << " ClapTrap Copy assignment operator\n";
	this->name = claptrap.name;
	this->hit_point = claptrap.hit_point;
	this->energy_point = claptrap.energy_point;
	this->attack_damage = claptrap.attack_damage;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << this->name << " ClapTrap Destructor\n";
}

//ClapTrap이 공격하면 target이 attckdamage만큼 hitpoint를 잃게됨
//energy point or hitpoint가 0이되면 아무것도 못함
void	ClapTrap::attack(const std::string& target){
	if (this->energy_point == 0 || this->hit_point == 0){
		std::cout << "ClapTrap can't do anything\n";
		return ;
	}
	this->energy_point--;
	std::cout << "ClapTrap " << this->name << " attacks " << target \
	<< ", causing " << this->attack_damage << " points of damage!\n" ;
}

void	ClapTrap::takeDamage(unsigned int amount){
//피해 당한거.?
	int	hp;

	hp = this->hit_point - amount;
	if (hp <= 0)
		this->hit_point = 0;
	else
		this->hit_point = hp;
	std::cout << "ClapTrap " << this->name << " took " 
			<< amount << " damage\n";
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->energy_point == 0 || this->hit_point == 0){
		std::cout << this->name << " can't do anything\n";
		return ;
	}
	this->energy_point--;
	this->hit_point += amount;
	std::cout << "ClapTrap " << this->name << " repaired itself "
			<< amount << " point\n";
}

std::string&	ClapTrap::getName(void){return name;}

unsigned int	ClapTrap::getHp(void){return this->hit_point;}

unsigned int	ClapTrap::getEp(void){return this->energy_point;}

unsigned int	ClapTrap::getDamage(void){return this->attack_damage;}
