/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:02:08 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 15:25:35 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType() const {
	return type;
}

Animal::Animal(std::string _type) {
	std::cout << "Constructor called for Animal Class" << std::endl;
	type = _type;
}

Animal::Animal(const Animal &other) {
	std::cout << "Copy constructor called for Animal Class" << std::endl;
	this->type = other.getType();
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Copy assignment operator called for Animal Class" << std::endl;
	if (this != &other) {
		type = other.getType();
	}
	return *this;
}

Animal::Animal() {
	std::cout << "Constructor called for Animal Class" << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor called for Animal Class" << std::endl;
}
