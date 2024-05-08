
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

typedef struct s_data
{
	int	data;
}	Data;

class Serializer
{
	private :
		Serializer();
        virtual ~Serializer();
        Serializer(const Serializer& obj);
        Serializer& operator= (const Serializer& obj);
	public :
		virtual void		abstract() = 0;
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif