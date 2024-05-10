
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& cont, const int& a)
{
	typename T::iterator iter = std::find(cont.begin(), cont.end(), a);
	if (iter == cont.end())
		throw std::runtime_error("Not found");
	return (iter);
}