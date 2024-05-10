
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	std::list<int> list;
	std::deque<int> deq;
	for (int i = 0; i < 5; ++i){
		vec.push_back(i*5);
		list.push_back(i+1);
		deq.push_back(i*2+2);
	}
	try
	{
		std::cout << *easyfind(vec, 15) << '\n';
		std::cout << *easyfind(vec, 0) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *easyfind(list, 4) << '\n';
		std::cout << *easyfind(list, 0) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *easyfind(deq, 8) << '\n';
		std::cout << *easyfind(deq, 7) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}