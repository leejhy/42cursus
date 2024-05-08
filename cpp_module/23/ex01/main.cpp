
#include <iostream>
#include "Serializer.hpp"

// void	f(){
// 	system("leaks ex01");
// }

int	main(void)
{
	Data		*_data;
	uintptr_t	tmp;
	Data		*result;

	_data = new Data;
	_data->data = 42;
	std::cout << "before data address " << (uintptr_t)_data << " value : " << _data->data << std::endl;
	tmp = Serializer::serialize(_data);
	std::cout << "tmp address " << tmp << std::endl;
	result = Serializer::deserialize(tmp);
	std::cout << "result data address " << (uintptr_t)result << " value : " << _data->data << std::endl;

	// atexit(f);
	delete _data;
}