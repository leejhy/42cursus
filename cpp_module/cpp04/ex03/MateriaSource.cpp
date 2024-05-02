
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	for (int i = 0; i < 4; i++)
		this->learned[i] = obj.learned[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
	for (int i = 0; i < 4; i++)
		this->learned[i] = obj.learned[i];
	
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (this->learned[i] != NULL)
			delete learned[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m){
	int	i;

	for (i = 0; i < 4; i++){
		if (learned[i] == NULL)
			break ;
	}
	if (i == 4)
		return ;
	this->learned[i] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type){
	AMateria* tmp = NULL;
	int i;

	for (i = 0; i < 4; i++){
		if (learned[i]->getType() == type)
			break ;
	}
	if (i == 4)
		return (0);
	if (type == "ice")
		tmp = new Ice();
	else if (type == "cure")
		tmp = new Cure();
	return (tmp);
}