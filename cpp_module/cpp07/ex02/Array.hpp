
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array//클래스 템플릿은 그 자체로 클래스는 아님
{
	private :
		T*				arr;
		unsigned int	length;
	public :
		Array() : arr(new T[0]), length(0){}
		Array(unsigned int n) : length(n){
			this->arr = new T[n];
			for (unsigned int i = 0; i < n; i++)
			this->arr[i] = 0;
		}
		~Array(){
			// std::cout << "destructor\n";
			delete[] this->arr;
			this->arr = NULL;
		}
		Array(const Array& obj) : arr(NULL), length(0){
			*this = obj;
		}
		Array& operator=(const Array& obj){
			if (&obj == this)
				return *this;
			if (this->arr){
				delete [] this->arr;
				this->arr = NULL;
			}
			this->length = obj.length;
			this->arr = new T[this->length];
			for (unsigned int i = 0; i < this->length; i++)
				this->arr[i] = obj.arr[i];
			return *this;
		}
		unsigned int size() const { return this->length; }
		T& operator[](long idx){
			// std::cout << "non";
			if (idx < 0 || idx >= this->length)
				throw OutOfRange();
			return this->arr[idx];
		}
		const T& operator[](long idx) const{
			// std::cout << "const";
			if (idx < 0 || idx >= this->length)
				throw OutOfRange();
			return this->arr[idx];
		}
		
		class OutOfRange : public std::exception
		{
			public :
				const char *what() const throw(){
					return "*===OUT OF RANGE===*";
				}
		};
};

#endif