/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:39:59 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/29 13:57:21 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() {
	const std::string& result = type;
	return result;
}

void Weapon::setType(const std::string& _type) {
	type = _type;
}

Weapon::Weapon(const std::string& _type) {
	type = _type;
}

Weapon::Weapon() {
}

Weapon::~Weapon() {
}
