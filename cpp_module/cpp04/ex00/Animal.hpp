
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		~Animal();
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);

		void	makeSound();
		const std::string&	Animal::getType();
};

#endif