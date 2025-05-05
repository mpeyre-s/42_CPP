/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:42:18 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/05 13:37:33 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie* horde = new Zombie[N];
	for (size_t i = 0; i < (size_t)N; i++)
		horde[i].setName(name);
	return horde;
}
