/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:13:09 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/26 11:59:55 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isValidInput(std::string user_input) {
	std::string charset = "0123456789+-/*";

	for (size_t i = 0; i < user_input.length(); ++i) {
		if (i % 2 == 1) {
			if (user_input[i] != ' ') {
				return false;
			}
		} else {
			if (charset.find(user_input[i]) == std::string::npos) {
				return false;
			}
		}
	}
	return true;
}

bool isOperator(char c) {
	std::string charset = "+-/*";
	if (charset.find(c) == std::string::npos)
		return false;
	return true;
}

RPN::RPN(std::string user_input) : arithmetic_expression(user_input) {
	if (isValidInput(arithmetic_expression) == false)
		throw BadProgramInputException();

	for (size_t i = 0; i < arithmetic_expression.length(); i++) {
		if (isOperator(arithmetic_expression[i])) {
			if (stack.size() < 2)
				throw std::runtime_error("operator but not enough numbers in stack for processing operation");

			int result;
			int nb1 = stack.top();
			stack.pop();
			int nb2 = stack.top();
			stack.pop();

			switch (arithmetic_expression[i]) {
				case '+':
					result = nb1 + nb2;
					break;
				case '-':
					result = nb2 - nb1;
					break;
				case '*':
					result = nb1 * nb2;
					break;
				case '/':
					if (nb1 == 0)
						throw std::runtime_error("division by zero");
					result = nb2 / nb1;
					break;
			}
			stack.push(result);
		}
		else if (isdigit(arithmetic_expression[i])) {
			stack.push(arithmetic_expression[i] - '0');
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("invalid RPN expression");

	std::cout << stack.top() << std::endl;
}

RPN::RPN(const RPN &other) {
	this->arithmetic_expression = other.arithmetic_expression;
	this->stack = other.stack;
}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		arithmetic_expression = other.arithmetic_expression;
		stack = other.stack;
	}
	return *this;
}

RPN::~RPN() {}
