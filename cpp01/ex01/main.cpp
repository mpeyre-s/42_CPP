/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:40:44 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/28 17:41:49 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av) {
	if (ac == 3) {
		int nb_zombie = atoi(av[1]);
		if (nb_zombie <= 0)
		{
			std::cout << "\033[1;31mError: The number of zombies must be positive"
					  << ".\033[0m" << std::endl;
			return 0;
		}
		Zombie *zombie = zombieHorde(nb_zombie, std::string(av[2]));
		for (size_t i = 0; i < (size_t)nb_zombie; i++)
			zombie[i].announce();
		delete [] zombie;
	}
	else {
		std::cout << "\033[1;31mTo create a horde of zombies, use in terminal : \033[0m"
				  << "\033[1;32m./moar_brainz [nb_zombie] [zombie_name]\033[0m" << std::endl;
	}
	return 0;
}
