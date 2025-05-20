/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:50:47 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 13:50:05 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int nb) {
	typename T::iterator it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw std::runtime_error("Value not found in the container");
	return it;
}
