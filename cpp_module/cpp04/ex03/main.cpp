
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
// void	f(){
// 	system("leaks ex03");
// }

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp1;
	AMateria* tmp2;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	// me->unequip(0);
	// delete tmp1;
	delete bob;
	delete me;
	delete src;
	// atexit(f);
	return 0;
}
/*
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp1;
	AMateria* tmp2;
	// AMateria* tmp3;
	// AMateria* tmp4;
	// AMateria* tmp5;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	// tmp3 = src->createMateria("cure");
	// me->equip(tmp3);
	// tmp4 = src->createMateria("cure");
	// me->equip(tmp4);
	// tmp5 = src->createMateria("cure");
	// me->equip(tmp5);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	// me->use(2, *bob);
	// me->use(3, *bob);
	// me->use(4, *bob);
	// me->unequip(0);
	// me->unequip(1);
	// me->unequip(2);
	// me->unequip(3);
	// me->unequip(4);
	// delete tmp1;
	// delete tmp2;
	// delete tmp3;
	// delete tmp4;
	// delete tmp5;
	delete bob;
	delete me;
	delete src;
	// atexit(f);
	return 0;
}*/