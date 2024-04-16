
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected :
		std::string				name;
		unsigned int			hit_point;//hp
		unsigned int			energy_point;//ep
		unsigned int			attack_damage;
	public :
		ClapTrap();
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap& claptrap);
		~ClapTrap();
		//OCCF
		ClapTrap(std::string name);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string&	getName(void);
		unsigned int	getHp(void);
		unsigned int	getEp(void);
		unsigned int	getDamage(void);
};

#endif