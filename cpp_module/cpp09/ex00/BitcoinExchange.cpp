
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& file) 
: data("data.csv"), input(file)
{
	//여기서는 길이만 세서 쪼개기
	std::ifstream	ifs;
	std::string		line;
	std::string		date;
	int 			cnt1;
	int 			cnt2;

	ifs.open(file.c_str());//input.txt
	if (!ifs.is_open())
		throw std::runtime_error("OPEN ERROR THROW");
	while (std::getline(ifs, line)){
		cnt1 = 0;
		cnt2 = 0;
		for (size_t i = 0; line[i] != '|'; ++i){
			if (!(('0' <= line[i] && line[i] <= '9') 
				|| line[i] == ' ' || line[i] == '-'))
				throw std::runtime_error("DATE WRONG CHARACTER THROW");
			if (i == 11)//파이프문자 인덱스가 11
				throw std::runtime_error("DATE TOO LONG THROW");
		}
		for (size_t i = 13; i < line.length(); ++i){
			if (!(('0' <= line[i] && line[i] <= '9') 
				|| line[i] == '-' || line[i] == '.'))
				throw std::runtime_error("VALUE WRONG CHARACTER THROW");
			if (line[i] == '.')
				cnt1++;
			if (line[i] == '-')
				cnt2++;
			//소수점 미만 몇개 들어올지 모르니까 길이계산 x
		}
		if (cnt1 > 1 || cnt2 > 1)//둘중하나라도 1개 초과면 에러임
			throw std::runtime_error("VALUE WRONG CHARACTER THROW");
	}
	ifs.close();
}

BitcoinExchange::~BitcoinExchange(){
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
	(void)obj;
	return *this;
}

void BitcoinExchange::openDatabase(){
	std::ifstream	ifs;
	std::string 	line;
	float			value;
	ifs.open(this->data.c_str());
	if (!ifs.is_open())
		throw std::runtime_error("OPEN ERROR THROW");
	while (std::getline(ifs, line)){
		std::istringstream	ss(line);
		std::string			first;
		std::string			second;
		std::getline(ss, first, ',');
		std::getline(ss, second);
		value = std::atof(second.c_str());
		this->map.insert(std::make_pair(first, value));
	}
	ifs.close();
	// for (auto i = map.begin(); i != map.end(); i++){
	// 	std::cout << i->first << ' ' << i->second << '\n';
	// }
}

void	BitcoinExchange::inputData(){
	std::ifstream	ifs;
	std::string		line;
	
	ifs.open(this->input.c_str());
	while (std::getline(ifs, line)){
		std::istringstream	ss(line);
		std::string			tmp;
		int					date;
		// '-'기준으로 파싱-> 유효성검사 -> 에러 throw,
		// 에러 아닐때 std::string으로 날짜갖고있고 map에서 string으로 value 뽑아서 파이프 뒤 숫자랑 곱해서 출력

		while (std::getline(ss, tmp, '-')){
			if (tmp[0] == '-')
				throw std::runtime_error("WRONG ARGUMENT THROW");
			if (tmp.length() > 4)
				throw std::runtime_error("TOO LONG THROW");
			// date = std::atoi(tmp.c_str());
			// if (date > )
		}
	}
	ifs.close();
}