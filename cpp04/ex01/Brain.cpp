/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:42:43 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 14:47:03 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignement constructor called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	std::string activities[5] = {"Sleeping", "Eating", "Barking", "Running", "Digging"};
	for (int i = 0; i < 100; i++) {
		ideas[i] = "Thinking of " + activities[i % 5];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
