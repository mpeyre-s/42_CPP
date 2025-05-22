/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:25:53 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/22 14:55:04 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		try {
			std::string input_file = av[1];
			BitcoinExchange app(input_file);
		}
		catch(const std::exception& e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	} else {
		std::cout << "\033[1;31mError:\033[0m Usage: ./btc input_file.txt" << std::endl;
		std::cout << "\033[1;33mInput file format:\033[0m" << std::endl;
		std::cout << "  • Each line must be in format: \"\033[1;36mdate | value\033[0m\"" << std::endl;
		std::cout << "  • Date must be in format \"\033[1;36mYYYY-MM-DD\033[0m\"" << std::endl;
		std::cout << "  • Value must be a positive float or integer between 0 and 1000" << std::endl;
	}
	return 0;
}
