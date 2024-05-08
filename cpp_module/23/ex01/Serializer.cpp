
#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer& obj){ (void)obj; }
Serializer& Serializer::operator= (const Serializer& obj){ (void)obj; return *this;}

uintptr_t	Serializer::serialize(Data* ptr){
	//ptr 을 uintptr_t로 변경해서 리턴
	uintptr_t	tmp;

	tmp = reinterpret_cast<uintptr_t>(ptr);
	return (tmp);
}

Data*		Serializer::deserialize(uintptr_t raw){
	//uintptr_t를 Data 포인터로 변환해서 리턴
	Data	*tmp;

	tmp = reinterpret_cast<Data *>(raw);
	return (tmp);
}
