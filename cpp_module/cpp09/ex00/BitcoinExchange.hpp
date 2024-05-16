#pragma once

#include <string>
#include <algorithm>
#include <map>
class BitcoinExchange
{
	private :
		std::string	data;
		std::string input_file;
		std::map<std::string, float> map;// date, value
		bool isValidValue(const std::string& split);
		BitcoinExchange();
	public :
		BitcoinExchange(const std::string& file);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		void openDatabase();
		void inputData();
};