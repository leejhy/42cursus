
#include "whatever.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// int	main(void)
// {
// 	char	ca, cb;
// 	int		ia, ib;
// 	float	fa, fb;
// 	double	da, db;

// 	ca = 'A', cb = 'B';
// 	ia = 42, ib = -442;
// 	fa = 123.45, fb = 234.56;
// 	da = 4343.4321, db = 2312.23;

// 	std::cout << "char : "<< ca << ' ' << cb << '\n';
// 	std::cout << "int : "<< ia << ' ' << ib << '\n';
// 	std::cout << "float : "<< fa << ' ' << fb << '\n';
// 	std::cout << "double : "<< da << ' ' << db << '\n';

// 	swap (ca, cb);
// 	swap (ia, ib);
// 	swap (fa, fb);
// 	swap (da, db);
// 	std::cout << "char : " << ca << ' ' << cb << '\n';
// 	std::cout << "int : "  << ia << ' ' << ib << '\n';
// 	std::cout << "float : " << fa << ' ' << fb << '\n';
// 	std::cout << "double : " << da << ' ' << db << '\n';
// 	std::cout << "\n======================\n\n";

// 	std::cout << "char : " << min(ca,cb) << '\n';
// 	std::cout << "int : " << min(ia,ib) << '\n';
// 	std::cout << "float : " << min(fa,fb) << '\n';
// 	std::cout << "double : " << min(da,db) << '\n';
// 	std::cout << "\n======================\n\n";

// 	std::cout << "char : " << max(ca,cb) << '\n';
// 	std::cout << "int : " << max(ia,ib) << '\n';
// 	std::cout << "float : " << max(fa,fb) << '\n';
// 	std::cout << "double : " << max(da,db) << '\n';
// 	std::cout << "\n======================\n\n";

// 	std::cout << max(2323,-12) << '\n';
// 	std::cout << min(2323,-12) << '\n';
// 	std::cout << max(1,1) << '\n';
// 	std::cout << min(2,2) << '\n';
// }