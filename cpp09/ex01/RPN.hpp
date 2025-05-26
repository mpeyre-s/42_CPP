/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:12:27 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/26 11:32:52 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class RPN {
private:
	std::string arithmetic_expression;
	std::stack<int> stack;
public:
	RPN(std::string user_input);
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	~RPN();

	class BadProgramInputException : public std::exception {
		virtual const char* what() const throw() {
			return "Bad program input";
		}
	};
};
