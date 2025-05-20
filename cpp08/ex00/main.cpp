/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:49:58 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 14:05:43 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	int ValueToFind = 11;

	std::vector<int> vec;
	for (size_t i = 0; i < 10; i++)
		vec.push_back(i);
	try {
		std::vector<int>::iterator it = easyfind(vec, ValueToFind);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
