
#pragma once

#include <vector>

class Span
{
	private :
		std::vector<int>	vec;
		unsigned int		size;
		Span();
	public :
		~Span();
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		//
		Span(unsigned int n);
		void	addNumber(int n);
		template <typename T>
		void	addNumberRange(T start, T end, int value){
			unsigned int cnt = 0;
			for (; start != end; ++start){
				vec.push_back(value);
				cnt++;
			}
			this->size += cnt;
		}
		unsigned int getSize();
		long	shortestSpan();
		long	longestSpan();
		void	print();
};