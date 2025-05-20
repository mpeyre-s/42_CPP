/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:34:42 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 10:43:07 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, T &b) {
	if (a >= b)
		return b;
	return a;
}

template <typename T>
T max(T &a, T &b) {
	if (a <= b)
		return b;
	return a;
}
