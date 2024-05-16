
#include "RPN.hpp"
#include <iostream>
#include <sstream>
RPN::RPN(){}

RPN::RPN(const std::string str){
	for (size_t i = 0; i < str.length(); i++){
		if (str[i] == ' ')
			continue ;
		if (!('0' <= str[i] && str[i] <= '9') &&
			str[i] != '-' && str[i] != '+' && 
			str[i] != '*' && str[i] != '/')
			throw std::runtime_error("error");
	}
	this->input = str;
	split();
}

RPN::~RPN(){}

RPN::RPN(const RPN& obj){
	*this = obj;
}

RPN& RPN::operator=(const RPN& obj){
	if (this == &obj)
		return *this;
	this->stack = obj.stack;
	return *this;
}

void	RPN::calculate(char op){
	int t1, t2;
	int	result = 0;

	t2 = this->stack.top();
	this->stack.pop();
	t1 = this->stack.top();
	this->stack.pop();
	if (op == '+'){
		result = t1 + t2;
	}
	else if (op == '-'){
		result = t1 - t2;
	}
	else if (op == '*'){
		result = t1 * t2;
	}
	else if (op == '/'){
		if (t2 == 0)
			throw std::runtime_error("you can't divide by 0");
		result = t1 / t2;
	}
	this->stack.push(result);
}

void RPN::split(){
	std::istringstream	ss(this->input);
	std::string			buf;
	int					nb = 0;

	while (std::getline(ss, buf, ' ')){
		if (buf.length() > 1)//음수, 10 이상, 에러
			throw std::runtime_error("too long argument");
		if (buf == "*" || buf == "-" || buf == "+" || buf == "/"){
			if (this->stack.size() >= 2)// == ? > ?
				calculate(buf[0]);
			else
				throw std::runtime_error("operator error");
			continue;
		}
		nb = std::atoi(buf.c_str());
		if (nb < 0 || nb > 9)
			throw std::runtime_error("out of range number");
		//decimal, range limit complete
		this->stack.push(nb);
	}
}

void RPN::print(){
	if (this->stack.size() != 1)
		throw std::runtime_error("incomplete calculate");
	std::cout << stack.top() << std::endl;
}