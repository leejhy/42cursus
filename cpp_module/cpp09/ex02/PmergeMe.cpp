
#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& obj){ *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){
	if (this == &obj)
		return *this;
	return *this;
}

void PmergeMe::parsing(int argc, char **argv){
	this->arg_size = argc - 1;
	char *tmp;
	long nb;

	for (uint i = 1; i <= this->arg_size; i++){
		tmp = argv[i];
		while (*tmp){
			if (!('0' <= *tmp && *tmp <= '9'))
				throw std::runtime_error("argument is not number");
			tmp++;
		}
		nb = std::atol(argv[i]);
		if (nb < INT_MIN || INT_MAX < nb)
			throw std::runtime_error("argument is too large");
		this->vec_parse.push_back(static_cast<int>(nb));
		this->deq_parse.push_back(static_cast<int>(nb));
	}
}

void	PmergeMe::makeJacobsthal(){
	uint tmp;

	this->jacobsthal_nb.push_back(1);
	this->jacobsthal_nb.push_back(3);
	for (uint i = 2; i < this->vec_parse.size(); ++i)
	{
		tmp = this->jacobsthal_nb[i - 1] + 2 * this->jacobsthal_nb[i - 2];
		this->jacobsthal_nb.push_back(tmp);
		if (this->vec_parse.size() <= tmp)
			break ;
	}
}

PmergeMe::PmergeMe(int argc, char **argv){
	clock_t start, end;

	parsing(argc, argv);
	makeJacobsthal();
	std::cout << "Before:\t";
	if (this->arg_size > 4){
		for (uint i = 0; i < 4; ++i)
			std::cout << this->vec_parse[i] << ' ';
		std::cout << "[...]\n";
	}
	else{
		for (uint i = 0; i < this->arg_size; ++i)
			std::cout << this->vec_parse[i] << ' ';
		std::cout << '\n';
	}
	start = clock();
	fordJohnson(this->vec_parse, 1);
	end = clock();
	std::cout << "After:\t";
	if (this->arg_size > 4){
		for (uint i = 0; i < 4; ++i)
			std::cout << this->sorted_vec[i] << ' ';
		std::cout << "[...]\n";
	}
	else{
		for (uint i = 0; i < this->arg_size; ++i)
			std::cout << this->sorted_vec[i] << ' ';
		std::cout << '\n';
	}
	std::cout << "Time to process a range of " << this->arg_size << " elements with std::vector : " << (end - start) << " ms" << std::endl;

	// std::cout << "Before: ";
	// if (this->arg_size > 4){
	// 	for (uint i = 0; i < 4; ++i)
	// 		std::cout << this->deq_parse[i] << ' ';
	// 	std::cout << "[...]\n";
	// }
	// else{
	// 	for (uint i = 0; i < this->arg_size; ++i)
	// 		std::cout << this->deq_parse[i] << ' ';
	// 	std::cout << '\n';
	// }
	start = clock();
	fordJohnson(this->deq_parse, 1);
	end = clock();
	// std::cout << "After: ";
	// if (this->arg_size > 4){
	// 	for (uint i = 0; i < 4; ++i)
	// 		std::cout << this->sorted_deq[i] << ' ';
	// 	std::cout << "[...]\n";
	// }
	// else{
	// 	for (uint i = 0; i < this->arg_size; ++i)
	// 		std::cout << this->sorted_deq[i] << ' ';
	// 	std::cout << '\n';
	// }

	std::cout << "Time to process a range of " << this->arg_size << " elements with std::deque : " << (end - start) << " ms" << std::endl;
	if (isSorted(this->sorted_vec))
			std::cout << "Sorted !!\n";
		else
			std::cout << "NOT Sorted !!\n";
	if (isSorted(this->sorted_deq))
			std::cout << "Sorted !!\n";
		else
			std::cout << "NOT Sorted !!\n";
}

void	PmergeMe::fordJohnson(std::vector<int>& vec, uint pos){
	//merge sort
	// std::cout << "vec ford !\n";
	for (uint i = 0; i < vec.size(); i += (pos * 2)){
		if (i + (pos * 2) > this->arg_size)
			break ;
		if (vec[i] < vec[i + pos]){
			for (uint j = 0; j < pos; ++j){
				std::swap(vec[i + j], vec[i + pos + j]);
			}
		}
	}
	if (vec.size() >= pos * 4)
		fordJohnson(vec, pos * 2);
	else{
		insertionSort(vec, pos);
	}
}

void	PmergeMe::fordJohnson(std::deque<int>& deq, uint pos){
	//merge sort
	// std::cout << "deq ford !\n";
	for (uint i = 0; i < deq.size(); i += (pos * 2)){
		if (i + (pos * 2) > this->arg_size)
			break ;
		if (deq[i] < deq[i + pos]){
			for (uint j = 0; j < pos; ++j){
				std::swap(deq[i + j], deq[i + pos + j]);
			}
		}
	}
	if (deq.size() >= pos * 4)
		fordJohnson(deq, pos * 2);
	else{
		insertionSort(deq, pos);
	}
}

void	PmergeMe::insertionSort(std::vector<int>& vec, uint chunk_size){
	// std::cout << "vec insert !\n";
	std::vector<int>	a;
	std::vector<int>	b;
	
	for (uint i = 0; i < vec.size(); i += (chunk_size * 2)){//이거 수정해야함
		if (i + chunk_size > vec.size()){
			for (uint j = i; j < this->arg_size; ++j){
				if (chunk_size == 1 && this->arg_size & 1){
					b.push_back(vec[j]);
					break ;
				}
				a.push_back(vec[j]);
			}
			break ;
		}
		else if (i + chunk_size * 2 > vec.size()){
			for (uint j = 0; j < chunk_size; ++j)
				b.push_back(vec[i + j]);
			for (uint j = i + chunk_size; j < this->arg_size; ++j)
				a.push_back(vec[j]);
			break ;
		}
		for (uint j = 0; j < chunk_size; ++j){
			a.push_back(vec[i + j]);
			b.push_back(vec[i + chunk_size + j]);
		}
	}
	bool	flag = false;
	int insert_cnt = 0;
	for (int loop = 0; flag == false && loop < static_cast<int>(this->jacobsthal_nb.size()); ++loop)
	{
		long search_end = 0;
		uint select = (this->jacobsthal_nb[loop] * chunk_size) - chunk_size;

		if (loop == 0){
			a.insert(a.begin(), b.begin(), b.begin() + chunk_size);
			continue ;
		}
		if (loop != 0)
			search_end = (this->jacobsthal_nb[loop - 1] * chunk_size) - chunk_size;
		if (select >= b.size()){
			select -= ((select - b.size()) + chunk_size);
			flag = true;
		}
		uint	target;
		while (search_end < select){
			target = select;
			long mid;
			int low = 0;
			int high = select / chunk_size + insert_cnt;
			if (b[target] < a[0]){
				a.insert(a.begin(), b.begin() + target, b.begin() + target + chunk_size);
				++insert_cnt;
				select -= chunk_size;
				continue ;
			}
			else if (b[target] > a[(high) * chunk_size]){
				a.insert(a.begin() + (high+1) * chunk_size,\
						 b.begin() + target, b.begin() + target + chunk_size);
				++insert_cnt;
				select -= chunk_size;
				continue ;
			}

			while (low + 1 < high){
				mid = (high + low) / 2;
				if (a[mid * chunk_size] < b[target])
					low = mid;
				else
					high = mid;
			}
			if (a[high * chunk_size] < b[target])
				a.insert(a.begin() + ((high + 1) * chunk_size),\
						 b.begin() + target, b.begin() + target + chunk_size);
			else
				a.insert(a.begin() + (high * chunk_size),\
						 b.begin() + target, b.begin() + target + chunk_size);
			++insert_cnt;
			select -= chunk_size;
		}
	}
	if (chunk_size > 1)
		insertionSort(a, chunk_size / 2);
	else
		this->sorted_vec = a;
}

void	PmergeMe::insertionSort(std::deque<int>& deq, uint chunk_size){
	// std::cout << "deq insert !\n";

	std::deque<int>	a;
	std::deque<int>	b;
	
	for (uint i = 0; i < deq.size(); i += (chunk_size * 2)){//이거 수정해야함
		if (i + chunk_size > deq.size()){
			for (uint j = i; j < this->arg_size; ++j){
				if (chunk_size == 1 && this->arg_size & 1){
					b.push_back(deq[j]);
					break ;
				}
				a.push_back(deq[j]);
			}
			break ;
		}
		else if (i + chunk_size * 2 > deq.size()){
			for (uint j = 0; j < chunk_size; ++j)
				b.push_back(deq[i + j]);
			for (uint j = i + chunk_size; j < this->arg_size; ++j)
				a.push_back(deq[j]);
			break ;
		}
		for (uint j = 0; j < chunk_size; ++j){
			a.push_back(deq[i + j]);
			b.push_back(deq[i + chunk_size + j]);
		}
	}
	bool	flag = false;
	int insert_cnt = 0;
	for (int loop = 0; flag == false && loop < static_cast<int>(this->jacobsthal_nb.size()); ++loop)
	{
		long search_end = 0;
		uint select = (this->jacobsthal_nb[loop] * chunk_size) - chunk_size;

		if (loop == 0){
			a.insert(a.begin(), b.begin(), b.begin() + chunk_size);
			continue ;
		}
		if (loop != 0)
			search_end = (this->jacobsthal_nb[loop - 1] * chunk_size) - chunk_size;
		if (select >= b.size()){
			select -= ((select - b.size()) + chunk_size);
			flag = true;
		}
		uint	target;
		while (search_end < select){
			target = select;
			long mid;
			int low = 0;
			int high = select / chunk_size + insert_cnt;
			if (b[target] < a[0]){
				a.insert(a.begin(), b.begin() + target, b.begin() + target + chunk_size);
				++insert_cnt;
				select -= chunk_size;
				continue ;
			}
			else if (b[target] > a[(high) * chunk_size]){
				a.insert(a.begin() + (high+1) * chunk_size,\
						 b.begin() + target, b.begin() + target + chunk_size);
				++insert_cnt;
				select -= chunk_size;
				continue ;
			}

			while (low + 1 < high){
				mid = (high + low) / 2;
				if (a[mid * chunk_size] < b[target])
					low = mid;
				else
					high = mid;
			}
			if (a[high * chunk_size] < b[target])
				a.insert(a.begin() + ((high + 1) * chunk_size),\
						 b.begin() + target, b.begin() + target + chunk_size);
			else
				a.insert(a.begin() + (high * chunk_size),\
						 b.begin() + target, b.begin() + target + chunk_size);
			++insert_cnt;
			select -= chunk_size;
		}
	}
	if (chunk_size > 1)
		insertionSort(a, chunk_size / 2);
	else
		this->sorted_deq = a;
}

bool	PmergeMe::isSorted(std::vector<int>& vec){
	for (uint i = 0; i < vec.size()-1; ++i){
		if (vec[i] > vec[i+1])
			return false;
	}
	return true;
}

bool	PmergeMe::isSorted(std::deque<int>& deq){
	for (uint i = 0; i < deq.size()-1; ++i){
		if (deq[i] > deq[i+1])
			return false;
	}
	return true;
}