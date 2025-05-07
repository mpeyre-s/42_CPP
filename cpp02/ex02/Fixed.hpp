/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:53:23 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/07 16:32:38 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixed_point_value;
	static const int fraction_bits = 8;

public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &old_obj);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
