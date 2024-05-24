
#include "Cat.hpp"
#include <iostream>

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat default constuctor\n";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal(cat){
	*this = cat;
	std::cout << "Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& cat){
	std::string tmp;
	Brain *tbrain = new Brain();

	delete this->brain;
	this->brain = NULL;
	this->type = cat.type;
	for (int i = 0; i < 100; i++){
		tmp = cat.brain->getIdeas(i);
		tbrain->setIdeas(i, tmp);
	}
	this->brain = tbrain;
	std::cout << "Dog copy assignment operator\n";
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor\n";
}

void	Cat::makeSound() const{
	std::cout << "Cacacacacacacactttt\n";
	std::cout << this->brain->getIdeas(10) << std::endl;
}
