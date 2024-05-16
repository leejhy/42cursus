
#include <iostream>
#include <sstream>

int	main(void)
{
	std::string str = "2012-01-11 | 1";
	std::string buf;
	std::istringstream	ss(str);

	std::getline(ss, buf, ' ');
	std::cout << buf << '\n';
	std::getline(ss, buf, ' ');
	std::cout << buf << '\n';
	std::getline(ss, buf, ' ');
}
	std::cout << buf << '\n';