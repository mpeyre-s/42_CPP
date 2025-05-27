/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:19:34 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/27 12:59:17 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> database;
	std::map<std::string, float> user_input;

public:
	BitcoinExchange(std::string &input_file);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	class FileUnopenableException : public std::exception {
	private:
		std::string message;
	public:
		FileUnopenableException(const std::string& filename) : message("could not open file " + filename + " .") {}
		virtual const char* what() const throw() { return message.c_str(); }
		virtual ~FileUnopenableException() throw() {}
	};
};
