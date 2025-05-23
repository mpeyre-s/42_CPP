/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:29:52 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 11:36:08 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const {
	std::cout << "*Ouuuaaaaf Ouuaaffff*" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Copy constructor called for Dog Class" << std::endl;
	this->type = other.getType();
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Copy assignment operator called for Dog Class" << std::endl;
	if (this != &other) {
		type = other.getType();
	}
	return *this;
}

Dog::Dog() {
	std::cout << "Constructor called for Dog Class" << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	std::cout << "Destructor called for Dog Class" << std::endl;
}
