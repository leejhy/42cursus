
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& file) 
: data("data.csv"), input_file(file)
{}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
	if (this == &obj)
		return *this;
	this->data = obj.data;
	this->input_file = obj.input_file;
	this->map = obj.map;
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
	if (!ifs.is_open())
		throw std::runtime_error("OPEN ERROR THROW");
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

		if (line == "date | value")
			continue;
		std::getline(ss, split, ' ');
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
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
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
		while (1){
			if (this->map.find(key) != this->map.end())
				break ;
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
		std::getline(ss, split, ' ');
		if (split != "|")
			throw std::runtime_error("WRONG DATE FORMAT THROW");
		std::getline(ss, split, ' ');//여기서 나온건 숫자 value밖에 없음
		if (!isValidValue(split)){
			std::cout << "Error: not a positive number.\n";
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