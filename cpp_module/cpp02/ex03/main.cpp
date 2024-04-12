
#include "Point.hpp"

int main( void )
{
	Point a (0,0);
	Point b (10,0);
	Point c (10,10);
	Point p (10,11);

	std::cout << bsp(a, b, c, p) << std::endl;
}