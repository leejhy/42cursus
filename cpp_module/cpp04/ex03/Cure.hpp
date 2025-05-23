
#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		~Cure();
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);

		Cure* clone() const;
		void use(ICharacter& target);
};

#endif