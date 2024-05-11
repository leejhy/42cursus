
#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack
{
	private :
		std::deque<T> deq;
	public :
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack& obj){*this = obj;}
		MutantStack& operator=(const MutantStack& obj){this->deq = obj.deq; return *this;}
		// typedef typename std::stack<T>::container_type::iterator iterator; 
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		
};

template<typename T>
class MyIterator
{
	private :
		node<T>* cur;
	public :
		MyIterator(MutantStack<T>* cur) : cur(cur){}
		MyIterator& operator++(){//전 후위?
			cur = cur->next;
			return *this;
		}
		MyIterator& operator*(){
			return cur->data;
		}
		bool operator==(const MyIterator& ref){
			return (cur == ref.cur);
		}
		bool operator!=(const MyIterator& ref){
			return (cur != ref.cur);
		}
};