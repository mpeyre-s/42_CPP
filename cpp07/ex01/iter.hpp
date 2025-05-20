/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:46:24 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 10:59:59 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t len, Func f) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}
