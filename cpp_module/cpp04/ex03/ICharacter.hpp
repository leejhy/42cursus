
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

class AMateria;// 삭제 할지말지 고민

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif