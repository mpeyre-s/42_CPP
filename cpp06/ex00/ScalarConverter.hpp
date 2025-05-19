/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:03 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/19 15:59:57 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <climits>

class ScalarConverter {
private:
	ScalarConverter();

public:
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter& operator=(const ScalarConverter &obj);
	~ScalarConverter();

	static void convert(const std::string& literal);
};

#endif
