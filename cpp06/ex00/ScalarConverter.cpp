/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:48:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/19 13:39:23 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isInteger(const std::string &s) {
	if (s.empty())
		return false;

	size_t start = 0;
	if (s[0] == '+' || s[0] == '-') {
		start = 1;
		if (s.length() == 1) {
			return false;
		}
	}

	for (size_t i = start; i < s.length(); ++i) {
		if (!isdigit(s[i])) {
			return false;
		}
	}

	return true;
}

bool isFloat(const std::string &s) {
	if (s.empty())
		return false;

	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;

	size_t start = 0;
	if (s[0] == '+' || s[0] == '-')
		start = 1;

	bool hasDigits = false;
	bool hasDecimal = false;
	bool hasF = false;

	for (size_t i = start; i < s.length(); ++i) {
		if (isdigit(s[i])) {
			hasDigits = true;
		} else if (s[i] == '.' && !hasDecimal) {
			hasDecimal = true;
		} else if (i == s.length() - 1 && s[i] == 'f') {
			hasF = true;
		} else {
			return false;
		}
	}

	return hasDigits && hasF;
}

static void print_char(const std::string& literal) {
	std::cout << "char: ";

	std::istringstream iss(literal);
	int value;
	iss >> value;

	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "Impossible" << std::endl;
	} else if (static_cast<int>(literal[0]) < 32 || static_cast<int>(literal[0]) > 126) {
		std::cout << "Non displayable" << std::endl;
	} else if (literal.length() == 1 && std::isprint(literal[0])) {
		std::cout << "'" << literal[0] << "'" << std::endl;
	} else {
		std::cout << "Impossible" << std::endl;
	}
}

static void print_int(const std::string& literal) {
	std::cout << "int: ";

	if (literal.length() == 1) {
		std::cout << static_cast<int>(literal[0]) << std::endl;
		return;
	}

	std::istringstream iss(literal);
	int value;
	iss >> value;

	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "Impossible" << std::endl;
	} else if (value < INT_MIN && value > INT_MAX) {
		std::cout << "Impossible" << std::endl;
	} else {
		std::cout << value << std::endl;
	}
}

static void print_float(const std::string& literal) {
	std::cout << "float: ";

	if (literal == "nan" || literal == "nanf") {
		std::cout << "nanf" << std::endl;
	} else if (literal == "+inf" || literal == "-inf") {
		std::cout << literal << "f" << std::endl;
	} else if (literal == "+inff" || literal == "-inff") {
		std::cout << literal << std::endl;
	} else {
		try {
			float value;
			std::string temp = literal;

			if (!temp.empty() && temp[temp.length() - 1] == 'f')
				temp = temp.substr(0, temp.length() - 1);

			value = std::stof(temp);

			if (value == static_cast<int>(value))
				std::cout << value << ".0f" << std::endl;
			else
				std::cout << value << "f" << std::endl;
		}
		catch (const std::exception&) {
			std::cout << "Impossible" << std::endl;
		}
	}
}

static void print_double(const std::string& literal) {
	std::cout << "double: ";

	if (literal == "nan" || literal == "nanf") {
		std::cout << "nan" << std::endl;
	} else if (literal == "+inf" || literal == "-inf") {
		std::cout << literal << std::endl;
	} else if (literal == "+inff") {
		std::cout << "+inf" << std::endl;
	} else if (literal == "-inff") {
		std::cout << "-inf" << std::endl;
	} else {
		try {
			double value;
			std::string temp = literal;

			if (!temp.empty() && temp[temp.length() - 1] == 'f')
				temp = temp.substr(0, temp.length() - 1);

			value = std::stod(temp);

			if (value == static_cast<int>(value))
				std::cout << value << ".0" << std::endl;
			else
				std::cout << value << std::endl;
		}
		catch (const std::exception&) {
			std::cout << "Impossible" << std::endl;
		}
	}
}

void ScalarConverter::convert(const std::string& literal) {
	print_char(literal);
	print_int(literal);
	print_float(literal);
	print_double(literal);
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj) {
	(void)obj;
	return *this;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}
