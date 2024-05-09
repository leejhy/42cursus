
#include "Array.hpp"

// void f(){
// 	system("leaks ex02");
// }
int	main(void)
{
	Array<int> arr1(5);
	Array<float> arr2(5);
	for (int i = 0; i < 5; i++){
		float a = 0.6;
		arr1[i] =  i * 10;
		arr2[i] =  a + (i * 10);
	}
	arr1[3] = 2323;
	arr2[2] = 231.12;
	std::cout << "int : ";
	for (int i = 0; i < 5; i++){
		std::cout << arr1[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "float : ";
	for (int i = 0; i < 5; i++){
		std::cout << arr2[i] << ' ';
	}
	std::cout << '\n';
	try
	{
		// arr1[5];
		arr1[-1];
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\n=====================\n\n\n";
	const Array<int> con_arr1 = arr1;
	const Array<float> con_arr2 = arr2;
	std::cout << "const int : ";
	for (int i = 0; i < 5; i++){
		std::cout << con_arr1[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "const float : ";
	for (int i = 0; i < 5; i++){
		std::cout << con_arr2[i] << ' ';
	}
	std::cout << '\n';
	try
	{
		// con_arr1[5];
		con_arr1[-1];
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// atexit(f);
}