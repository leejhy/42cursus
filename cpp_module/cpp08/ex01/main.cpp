
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i+1);
	try
	{
		std::cout << *easyfind(vec, 5) << '\n';
		std::cout << *easyfind(vec, 0) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}