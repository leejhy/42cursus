#include "Dog.hpp"
#include <iostream>

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog default constuctor\n";
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal(dog){
	*this = dog;
	std::cout << "Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& dog){
	std::string tmp;
	Brain *tbrain = new Brain();

	delete this->brain;
	this->brain = NULL;
	this->type = dog.type;
	for (int i = 0; i < 100; i++){
		tmp = dog.brain->getIdeas(i);
		tbrain->setIdeas(i, tmp);
	}
	this->brain = tbrain;
	std::cout << "Dog copy assignment operator\n";
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor\n";
}

void	Dog::makeSound() const{
	std::cout << "Doododododododdoodooogggg\n";
	std::cout << this->brain->getIdeas(10) << std::endl;
}
