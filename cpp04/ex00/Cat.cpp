/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:28:10 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 11:36:10 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << "*Miaouuuuu*" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Copy constructor called for Cat Class" << std::endl;
	this->type = other.getType();
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Copy assignment operator called for Cat Class" << std::endl;
	if (this != &other) {
		type = other.getType();
	}
	return *this;
}

Cat::Cat() {
	std::cout << "Constructor called for Cat Class" << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	std::cout << "Destructor called for Cat Class" << std::endl;
}
