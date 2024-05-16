
#pragma once

#include <string>
#include <algorithm>
#include <stack>

class RPN
{
	private :
		std::string		input;
		std::stack<int> stack;
		RPN();
	public :
		RPN(const std::string str);
		~RPN();
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		void split();
		void calculate(char op);
		void print();
};
