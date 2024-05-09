
#include "iter.hpp"

// void	f(){
// 	system("leaks ex01");
// }

int	main(void)
{
	int		*arr1 = new int[10];
	float	*arr2 = new float[10];
	double	*arr3 = new double[10];
	const int	*arr4 = new const int[10]();

	for (int i = 0; i < 10; ++i)
		arr1[i] = i + 1;
	for (int i = 0; i < 10; ++i)
		arr2[i] = i + 1.5;
	for (int i = 0; i < 10; ++i)
		arr3[i] = i + 1.7;

	std::cout << "before int : ";
	for (int i = 0; i < 10; ++i)
		std::cout << arr1[i] << ' ';
	std::cout << '\n';

	std::cout << "before float: ";
	for (int i = 0; i < 10; ++i)
		std::cout << arr2[i] << ' ';
	std::cout << '\n';

	std::cout << "before double: ";
	for (int i = 0; i < 10; ++i)
		std::cout << arr3[i] << ' ';
	std::cout << "\n\n";

	iter(arr1, 10, Add);
	iter(arr2, 10, Add);
	iter(arr3, 10, Add);
	// iter<int>(arr1, 10, Add);
	// iter<float>(arr2, 10, Add);
	// iter<double>(arr3, 10, Add);
	

	std::cout << "after int : ";
	for (int i = 0; i < 10; ++i)
		std::cout << arr1[i] << ' ';
	std::cout << '\n';
	std::cout << "after float : ";
	for (int i = 0; i < 10; ++i)
		std::cout << arr2[i] << ' ';
	std::cout << '\n';
	std::cout << "after double : ";
	for (int i = 0; i < 10; ++i)
		std::cout << arr3[i] << ' ';
	std::cout << '\n';
	std::cout << "const : ";
	iter(arr4, 10, print);
	std::cout << '\n';
	// atexit(f);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
}