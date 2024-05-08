
#include <iostream>
#include <cstdlib>
#include <ctime>
//forbidden std::typeinfo
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	f(){
	system("leaks ex02");
}

Base * generate(void){
	int		ran;
	Base*	ptr = NULL;
	
	ran = rand() % 3;
	switch (ran){
		case 0:
			ptr = new A();
			break ;
		case 1:
			ptr = new B();
			break ;
		case 2:
			ptr = new C();
			break ;
		default:
			std::cout << "error impossible\n";
			break;
	}
	return (ptr);
}

void identify(Base* p){
	//실제 타입 식별후 출력
	Base *ptr;
	std::cout << "ptr identify\n";
	ptr = dynamic_cast<A*>(p);
	if (ptr != NULL){
		std::cout << "A class\n";
		return ;
	}
	ptr = dynamic_cast<B*>(p);
	if (ptr != NULL){
		std::cout << "B class\n";
		return ;
	}
	ptr = dynamic_cast<C*>(p);
	if (ptr != NULL){
		std::cout << "C class\n";
		return ;
	}
}

void identify(Base& p){
//forbid pointer
	std::cout << "ref identify\n";
	try
	{
		Base& result = dynamic_cast<A&>(p);
		(void)result;
		std::cout << "A class\n";
	}
	catch (std::exception& e)
	{
	}
	try
	{
		Base& result = dynamic_cast<B&>(p);
		(void)result;
		std::cout << "B class\n";
	}
	catch (std::exception& e)
	{
	}
	try
	{
		Base& result = dynamic_cast<C&>(p);
		(void)result;
		std::cout << "C class\n";
	}
	catch (std::exception& e)
	{
	}
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	A a;
	B b;
	C c;
	identify(b);
	identify(a);
	identify(c);
	std::cout << "============\n";

	Base* rand1 = generate();
	Base* rand2 = generate();
	Base* pa = new A;
	Base* pb = new B;
	Base* pc = new C;

	identify(pb);
	identify(pa);
	identify(pc);

	std::cout << "============\n";
	identify(rand1);
	identify(rand2);
	delete rand1;
	delete rand2;
	delete pa;
	delete pb;
	delete pc;
	atexit(f);
}