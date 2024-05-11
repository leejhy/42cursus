
#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <climits>

Span::Span(){}

Span::Span(unsigned int n){
	this->size = n;
}

Span::~Span(){}

Span::Span(const Span& obj){
	*this = obj;
}

Span& Span::operator=(const Span& obj){
	if (this == &obj)
		return *this;
	this->vec = obj.vec;
	this->size = obj.size;
	return *this;
}

void	Span::addNumber(int n){
	if (this->size == this->vec.size())
		throw std::runtime_error("*===Already filled in vector===*");
	vec.push_back(n);
}

long	Span::shortestSpan(){
	long	result = UINT_MAX;

	if (vec.empty() || vec.size() == 1)
		throw std::runtime_error("*===vector has no element===*");

	std::sort(vec.begin(), vec.end());
	for (unsigned i = 0; i < this->vec.size() - 1; ++i){
		if (vec[i] != vec[i + 1])
			result = std::min(result, static_cast<long>(std::abs(vec[i+1] - vec[i])));
	}
	return result;
}

long	Span::longestSpan(){
	long	result = 0;

	if (vec.empty() || vec.size() == 1)
		throw std::runtime_error("*===vector has no element===*");
	std::sort(vec.begin(), vec.end());
	result = std::abs(vec[0] - vec[this->vec.size() - 1]);
	return result;
}


void	Span::print(){
	for (unsigned int i = 0; i < this->vec.size(); i++){
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}

unsigned int Span::getSize(){
	return this->size;
}