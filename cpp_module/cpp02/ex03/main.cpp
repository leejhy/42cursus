
#include "Point.hpp"

int main( void )
{
	Point a (0,0);
	Point b (10,0);
	Point c (10,10);
	Point p1 (9,9);//edge
	Point p2 (10,10);//vertex
	Point p3 (10,11);//out
	Point p4 (5,4.9);//in

	std::cout << "edge : " << bsp(a, b, c, p1) << std::endl;
	std::cout << "vertex : " << bsp(a, b, c, p2) << std::endl;
	std::cout << "out : " << bsp(a, b, c, p3) << std::endl;
	std::cout << "in : " << bsp(a, b, c, p4) << std::endl;
}