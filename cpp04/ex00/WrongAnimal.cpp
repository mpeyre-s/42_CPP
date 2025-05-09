/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:39:54 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 12:55:58 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "*Generic WrongAnimal sound*" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) {
	std::cout << "Constructor called for WrongAnimal Class" << std::endl;
	type = _type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	this->type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		type = other.getType();
	}
	return *this;
}

WrongAnimal::WrongAnimal() {
	std::cout << "Constructor called for WrongAnimal Class" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor called for WrongAnimal Class" << std::endl;
}
