
#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(){
	std::stringstream ss;

	for (int i = 0; i < 100; i++){
		ss.str("");
		ss << i;
		this->ideas[i] = "hi_brain " + ss.str();
	}
	std::cout << "Brain Constructer\n";
}

Brain::Brain(const Brain& brain){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain copy\n";
}

Brain& Brain::operator=(const Brain& brain){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain copy assign\n";
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain Destructor\n";
}

std::string	Brain::getIdeas(int idx) const {
	if (idx < 0 || 99 < idx)
		return 0;
	return (this->ideas[idx]);
}

void	Brain::setIdeas(int idx, std::string const& value){
	std::stringstream ss;

	if (idx < 0 || 99 < idx)
		return ;
	this->ideas[idx] = value;
}