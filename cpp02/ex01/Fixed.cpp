/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:54:54 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/06 18:16:44 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Return raw nb without transform it to decimal point number
int Fixed::getRawBits(void) const {
	return fixed_point_value;
}

// Set nb after transformed it to fixed-point number (42,78 * 2ˆ8 = raw)
void Fixed::setRawBits(int const raw) {
	fixed_point_value = raw;
}

Fixed::Fixed(const int nb) {
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = nb << fraction_bits;
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(nb * (1 << fraction_bits));
}

float Fixed::toFloat(void) const {
	return (float)fixed_point_value / (1 << fraction_bits);
}

int Fixed::toInt(void) const {
	return fixed_point_value >> fraction_bits;
}

// Default constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	fixed_point_value = 0;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &old_obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_value = old_obj.getRawBits();
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		fixed_point_value = other.getRawBits();
	}
	return *this;
}

// Overload insertion operator <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
