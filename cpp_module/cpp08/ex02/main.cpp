
#include "MutantStack.hpp"
#include <list>
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout <<"========\n";
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;
	s.push(10);
	s.push(20);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.size() << std::endl;
	std::cout << s.top() << std::endl;

	std::cout <<"===================\n\n";

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::cout << "list  size : " << lst.size() << std::endl;
	std::list<int>::iterator lib = lst.begin();
	std::list<int>::iterator lie = lst.end();
	++lib;
	--lib;
	while (lib != lie)
	{
		std::cout << *lib << std::endl;
		++lib;
	}
	return 0;
}