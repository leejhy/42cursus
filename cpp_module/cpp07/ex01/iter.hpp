
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, const size_t size, void (*func)(T&))
{
	if (arr == NULL)
		return ;
	for (size_t i = 0; i < size; ++i)
		func(arr[i]);
}

template <typename T>
void iter(const T *arr, const size_t size, void (*func)(const T&))
{
	if (arr == NULL)
		return ;
	for (size_t i = 0; i < size; ++i)
		func(arr[i]);
}

template <typename T>
void	Add(T& nb)
{
	nb += 5;
}

template <typename T>
void	print(const T& nb)
{
	std::cout << nb << ' ';
}


#endif