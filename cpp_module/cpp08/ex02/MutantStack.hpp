
#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack& obj){*this = obj;}
		MutantStack& operator=(const MutantStack& obj){
			std::stack<T, Container>::operator=(obj);
			return *this;
		}
		typedef typename MutantStack<T, Container>::stack::container_type::iterator iterator;
		typedef typename MutantStack<T, Container>::stack::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T, Container>::stack::container_type::const_iterator const_iterator;

		iterator	begin(){ return this->c.begin(); }
		const_iterator	cbegin() const { return this->c.cbegin();}
		reverse_iterator rbegin() { return this->c.rbegin(); }
		iterator	end(){ return this->c.end();}
		const_iterator	cend() const { return this->c.cend();}
		reverse_iterator rend() { return this->c.rend(); }
};