
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& file) 
: data("data.csv"), input_file(file)
{
	//여기서는 길이만 세서 쪼개기
	size_t			i;
	std::ifstream	ifs;
	std::string		line;
	std::string		date;
	int 			cnt;

	ifs.open(file.c_str());//input.txt
	if (!ifs.is_open())
		throw std::runtime_error("OPEN ERROR THROW");
	while (std::getline(ifs, line)){
		cnt = 0;
		for (i = 0; line[i] && line[i] != '|'; ++i){
			// if (!(('0' <= line[i] && line[i] <= '9') 
			// 	|| line[i] == ' ' || line[i] == '-'))
			// 		throw std::runtime_error("DATE WRONG CHARACTER THROW11");
			// if (i == 11)//파이프문자 인덱스가 11더 커지면 throw
			// 	throw std::runtime_error("DATE TOO LONG THROW");
		}
		//i == ' ' i+1 == '|' ... 
		while (line[i]){
			if (line[i] == ' ' || line[i] == '|')
				i++;
			else
				break ;
		}
		for (; i < line.length(); ++i){
			// if (!(('0' <= line[i] && line[i] <= '9') 
			// 	|| line[i] == '-' || line[i] == '.')){
			// 		std::cout << line[i] << std::endl;
			// 		throw std::runtime_error("VALUE WRONG CHARACTER THROW22");
			// 	}
			if (line[i] == '.')
				cnt++;
			//소수점 미만 몇개 들어올지 모르니까 길이계산 x
		}
		if (cnt > 1)
			throw std::runtime_error("VALUE WRONG CHARACTER THROW44");
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

bool	BitcoinExchange::isValidValue(const std::string& split){
	for (size_t i = 0; i < split.length(); i++){
		if (!('0' <= split[i] && split[i] <= '9') &&
			split[i] != '.')
			return (false);
	}
	return (true);
}

void	BitcoinExchange::inputData(){
	std::tm			tm = {};
	std::ifstream	ifs;
	std::string		line;
	int				days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	ifs.open(this->input_file.c_str());
	while (std::getline(ifs, line)){
		std::string			split;
		std::istringstream	ss(line);
		int					month;
		int					year;
		int					day;
		double				value;
		std::string			key;
		std::string			key_print;
		char*				check;
		// '-'기준으로 파싱-> 유효성검사 -> 에러 throw,
		// 에러 아닐때 std::string으로 날짜갖고있고 map에서 string으로 value 뽑아서 파이프 뒤 숫자랑 곱해서 출력
		if (line == "date | value")
			continue;
		std::getline(ss, split, ' ');
		// std::istringstream	split_ss(split);//2020-01-20 이런 날짜가 들어감
		check = strptime(split.c_str(), "%Y-%m-%d", &tm);
		if (!check){
			std::cout << "Error: bad input => " << split << '\n';
			continue;
		}
		year = tm.tm_year + 1900;
		month = tm.tm_mon + 1;
		day = tm.tm_mday;
		if (year < 2009 || 2022 < year){
			std::cout << "Error: bad input => " << split << '\n';
			continue;
		}
		if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
			days[1] = 29;
		if (month < 1 || month > 12){
			std::cout << "Error: bad input => " << split << '\n';
			continue;
		}
		if (day < 1 || day > days[month-1]){
			std::cout << "Error: bad input => " << split << '\n';
			continue;
		}
		key = split;
		key_print = split;
		// std::cout << "before " << key << std::endl;
		while (1){
			if (this->map.find(key) != this->map.end()){
				break ;
			}
			tm.tm_mday--;
			std::time_t t;
			t = std::mktime(&tm);
			(void)t;
			char tmp[20];
			std::strftime(tmp, sizeof(tmp), "%Y-%m-%d", &tm);
			if (1900 + tm.tm_year <= 2008){
				throw std::runtime_error("OUT OF DATE RANGE THROW");
			}
			key = tmp;
		}
		// std::cout << "after " << key << std::endl;
		std::getline(ss, split, ' ');
		if (split != "|")
			throw std::runtime_error("WRONG DATE FORMAT THROW");
		std::getline(ss, split, ' ');//여기서 나온건 숫자 value밖에 없음
		if (!isValidValue(split)){
			std::cout << "Error: not a positive number(wrong number).\n";
			continue;
		}
		value = std::atof(split.c_str());
		if (value < 0){
			std::cout << "Error: not a positive number.\n";
			continue;
		}
		if (value > 1000){
			std::cout << "Error: too large a number.\n";
			continue;
		}
		std::cout << key_print << " => " << value << " = " << this->map[key] * value << '\n';
	}
	ifs.close();
}