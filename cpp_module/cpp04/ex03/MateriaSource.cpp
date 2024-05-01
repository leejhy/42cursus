
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
	// std::cout << "MateriaSource default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	for (int i = 0; i < 4; i++)
		this->learned[i] = obj.learned[i];
	// std::cout << "MateriaSource copy\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
	for (int i = 0; i < 4; i++)
		this->learned[i] = obj.learned[i];
	// std::cout << "MateriaSource copy assignment\n";
	
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (this->learned[i] != NULL)
			delete learned[i];
	}
	// std::cout << "MateriaSource Destructor\n";
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