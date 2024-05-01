
#include "Cat.hpp"
#include <iostream>

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat default constuctor\n";
	this->brain = new Brain();//default constructor
}

Cat::Cat(const Cat& cat) : Animal(cat){
	//brain도 복사해줘야함
	std::string tmp;

	this->type = cat.type;
	for (int i = 0; i < 100; i++){
		tmp = cat.brain->getIdeas(i);
		this->brain->setIdeas(i, tmp);
	}
	std::cout << "Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& cat){
	std::string tmp;

	this->type = cat.type;
	for (int i = 0; i < 100; i++){
		tmp = cat.brain->getIdeas(i);
		this->brain->setIdeas(i, tmp);
	}
	std::cout << "Cat copy assignment operator\n";
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
