#pragma once

#include <string>
#include <algorithm>
#include <map>
class BitcoinExchange
{
	private :
		std::string	data;
		std::string input;
		std::map<std::string, float> map;// date, value
		BitcoinExchange();
	public :
		BitcoinExchange(const std::string& file);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		void openData();
		void run();
};