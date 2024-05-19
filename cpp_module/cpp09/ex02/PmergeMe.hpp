
#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <deque>

typedef unsigned int uint;

class PmergeMe
{
	private :
		std::vector<int>	vec_parse;
		std::vector<int>	sorted_vec;
		std::deque<int>		deq_parse;
		std::deque<int>		sorted_deq;
		std::vector<int>	jacobsthal_nb;
		uint				arg_size;
		PmergeMe();
	public :
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		void	parsing(int argc, char **argv);
		void	makeJacobsthal();
		void	fordJohnson(std::vector<int>& main_chain, uint pos);
		void	insertionSort(std::vector<int>& vec, uint pos);

		void	fordJohnson(std::deque<int>& deq, uint pos);
		void	insertionSort(std::deque<int>& deq, uint pos);
		bool	isSorted(std::vector<int>& vec);
		bool	isSorted(std::deque<int>& deq);
};