/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:12:02 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/24 12:01:21 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		try {
			std::string user_input = av[1];
			RPN app(user_input);
		}
		catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

	}
	return 0;
}
