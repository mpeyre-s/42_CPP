/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:20:38 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/22 15:23:42 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool validDateFormat(std::string date) {
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++) {
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2) {
		bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (leapYear ? 29 : 28))
			return false;
	}

	return true;
}

BitcoinExchange::BitcoinExchange(std::string &input_file) {
	// .csv parsing into database map
	std::ifstream d_file("data.csv");
	if (!d_file.is_open())
		throw FileUnopenableException("data.csv");

	std::string d_line;
	while (std::getline(d_file, d_line)) {
		std::stringstream d_lineStream(d_line);
		std::string d_key;
		std::string d_value;
		if (std::getline(d_lineStream, d_key, ',') && std::getline(d_lineStream, d_value)) {
			char* endptr;
			float fd_value = strtof(d_value.c_str(), &endptr);
			database[d_key] = fd_value;
		}
	}
	d_file.close();

	// .txt parsing and processing line by line
	std::ifstream file(input_file);
	if (!file.is_open())
		throw FileUnopenableException(input_file);

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t delimPos = line.find(" | ");
		if (delimPos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string key = line.substr(0, delimPos);
		std::string value = line.substr(delimPos + 3);
		char* endptr;
		float f_value = strtof(value.c_str(), &endptr);

		if (!validDateFormat(key)) {
			std::cout << "Error: bad input => " << key << std::endl;
			continue;
		}
		else if (!f_value) {
			std::cout << "Error: invalid value => 0" << std::endl;
			continue;
		} else if (f_value >= 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		} else if (f_value <= 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		} else {
			std::map<std::string, float>::const_iterator it = database.upper_bound(key);
			if (it != database.begin()) {
				--it;
				float db_value = it->second;
				float result = f_value * db_value;
				std::cout << key << " => " << f_value << " = " << result << std::endl;
			} else {
				std::cout << "Error: no data available for date " << key << std::endl;
			}
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
