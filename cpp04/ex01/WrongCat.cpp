/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:40:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 13:22:37 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void WrongCat::makeSound() const {
	std::cout << "*Generic WrongCat sound*" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	this->type = other.getType();
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		type = other.getType();
	}
	return *this;
}

WrongCat::WrongCat() {
	std::cout << "Constructor called for WrongCat Class" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "Destructor called for WrongCat Class" << std::endl;
}
