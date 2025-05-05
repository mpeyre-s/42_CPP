/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:42:01 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/05 13:37:24 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name) {
	name = _name;
}

void Zombie::setName(const std::string& _name) {
	name = _name;
}

void Zombie::announce(void) {
	std::cout << name << " joined the horde" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " suffer in hellfire" << std::endl;
}

Zombie::Zombie() {
}
