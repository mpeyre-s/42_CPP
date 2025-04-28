/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:27:17 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/28 11:06:10 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; j < (int)std::strlen(av[i]); j++) {
				std::cout << (char)std::toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
