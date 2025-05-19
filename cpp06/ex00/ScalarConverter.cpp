/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:48:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/19 22:21:07 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isStrictlyInteger(const std::string& literal) {
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;

	if (i == literal.length())
		return false;

	for (; i < literal.length(); i++) {
		if (!std::isdigit(literal[i]))
			return false;
	}

	return true;
}

bool isStrictlyDouble(const std::string& literal) {
	if (literal.empty())
		return false;

	if (literal == "-inf" || literal == "+inf")
		return true;

	size_t i = 0;
	bool hasDecimalPoint = false;

	if (literal[0] == '-' || literal[0] == '+')
		i++;

	if (i == literal.length())
		return false;

	for (; i < literal.length(); i++) {
		if (literal[i] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
	}
	return hasDecimalPoint;
}

bool isStrictlyFloat(const std::string& literal) {
	if (literal.empty() || literal.length() < 2)
		return false;

	if (literal == "-inff" || literal == "+inff")
		return true;

	std::string withoutF = literal.substr(0, literal.length() - 1);

	return isStrictlyDouble(withoutF) && literal[literal.length() - 1] == 'f';
}

void print_char(int num, const std::string& literal) {
	std::cout << "char: ";

	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff" || literal.empty() || (literal.length() > 1 && !isdigit(literal[0]) && !isdigit(literal[1])))
		std::cout << "Impossible" << std::endl;
	else if (!isStrictlyInteger(literal) && !isStrictlyDouble(literal) && !isStrictlyFloat(literal) && literal.length() == 1)
		std::cout << "'" << literal[0] << "'" << std::endl;
	else if (num < 0 || num > 127)
		std::cout << "Impossible" << std::endl;
	else if (!isprint(num))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
}

void print_int(int num, const std::string& literal) {
	std::cout << "int: ";

	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff" || literal.empty())
		std::cout << "Impossible" << std::endl;
	else if (num < INT_MIN || num > INT_MAX || (literal.length() > 1 && !isdigit(literal[0]) && !isdigit(literal[1])))
		std::cout << "Impossible" << std::endl;
	else if (!isStrictlyInteger(literal) && !isStrictlyDouble(literal) && !isStrictlyFloat(literal) && literal.length() == 1)
		std::cout <<  static_cast<int>(literal[0]) << std::endl;
	else
		std::cout << num << std::endl;
}

void print_float(const std::string& literal) {
	std::cout << "float: ";

	if (literal.empty())
		std::cout << "Impossible" << std::endl;
	else if (literal == "nan" || literal == "nanf")
		std::cout << "nanf" << std::endl;
	else if (literal == "+inf" || literal == "-inf")
		std::cout << literal << "f" << std::endl;
	else if (literal == "+inff" || literal == "-inff")
		std::cout << literal << std::endl;
	else {
		try {
			std::string temp = literal;
			if (!temp.empty() && temp[temp.length() - 1] == 'f')
				temp = temp.substr(0, temp.length() - 1);

			char* endptr;
			float value = strtof(temp.c_str(), &endptr);

			if (*endptr != '\0')
				std::cout << "Impossible" << std::endl;
			else if (value == static_cast<int>(value))
				std::cout << value << ".0f" << std::endl;
			else
				std::cout << value << "f" << std::endl;
		}
		catch (const std::exception&) {
			std::cout << "Impossible" << std::endl;
		}
	}
}

void print_double(const std::string& literal) {
	std::cout << "double: ";

	if (literal.empty())
		std::cout << "Impossible" << std::endl;
	else if (literal == "nan" || literal == "nanf")
		std::cout << "nan" << std::endl;
	else if (literal == "+inf" || literal == "-inf")
		std::cout << literal << std::endl;
	else if (literal == "+inff")
		std::cout << "+inf" << std::endl;
	else if (literal == "-inff")
		std::cout << "-inf" << std::endl;
	else {
		try {
			std::string temp = literal;
			if (!temp.empty() && temp[temp.length() - 1] == 'f')
				temp = temp.substr(0, temp.length() - 1);

			char* endptr;
			double value = strtod(temp.c_str(), &endptr);

			if (*endptr != '\0')
				std::cout << "Impossible" << std::endl;
			else if (value == static_cast<int>(value))
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
	std::istringstream iss(literal);
	int num;
	iss >> num;

	print_char(num, literal);
	print_int(num, literal);
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
