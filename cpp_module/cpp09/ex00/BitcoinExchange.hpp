#pragma once

#include <string>
#include <algorithm>
#include <map>
class BitcoinExchange
{
	private :
		std::string	date;
		std::string value;
		std::map<std::string, int> map;// date, value
		BitcoinExchange();
	public :
		BitcoinExchange::BitcoinExchange(const std::string& file);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
};