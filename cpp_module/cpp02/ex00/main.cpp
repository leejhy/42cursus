
#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( a );
	Fixed	c;
	c = b;

	// std::cout << &a << std::endl;
	// std::cout << &b << std::endl;
	// std::cout << &c << std::endl; // 다 달라야함
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
