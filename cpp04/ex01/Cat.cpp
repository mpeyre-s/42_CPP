/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:28:10 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/10 11:24:53 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << "*Miaouuuuu*" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Copy constructor called for Cat Class" << std::endl;
	this->type = other.getType();
	this->brain = new Brain(*(other.brain));
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Copy assignment operator called for Cat Class" << std::endl;
	if (this != &other) {
		type = other.getType();
		delete brain;
		brain = new Brain(*(other.brain));
	}
	return *this;
}

Cat::Cat() {
	std::cout << "Constructor called for Cat Class" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Destructor called for Cat Class" << std::endl;
	delete brain;
}
