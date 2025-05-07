/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:54:54 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/07 16:59:46 by mathispeyre      ###   ########.fr       */
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
	fixed_point_value = nb << fraction_bits;
}

Fixed::Fixed(const float nb) {
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
	fixed_point_value = 0;
}

// Destructor
Fixed::~Fixed() {

}

// Copy constructor
Fixed::Fixed(const Fixed &old_obj) {
	this->fixed_point_value = old_obj.getRawBits();
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
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

bool Fixed::operator>(const Fixed& other) const {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> fraction_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->getRawBits() << fraction_bits) / other.getRawBits());
	return result;
}

Fixed& Fixed::operator++() {
	fixed_point_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	fixed_point_value++;
	return temp;
}

Fixed& Fixed::operator--() {
	fixed_point_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	fixed_point_value--;
	return temp;
}

Fixed Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}
