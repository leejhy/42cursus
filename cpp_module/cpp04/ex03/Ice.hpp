
#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		~Ice();
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif