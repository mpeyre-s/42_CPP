/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:11:41 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 11:47:34 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	try {
		std::cout << "=== Creating an array of integers with size 5 ===" << std::endl;
		Array<int> a(5);

		for (size_t i = 0; i < a.size(); ++i)
			a[i] = i * 10;

		std::cout << "Content of array a: ";
		for (size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Copying array a into b ===" << std::endl;
		Array<int> b = a;

		std::cout << "Modifying a[0] = 999" << std::endl;
		a[0] = 999;

		std::cout << "Content of array a: ";
		for (size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		std::cout << "Content of array b (should be unchanged): ";
		for (size_t i = 0; i < b.size(); ++i)
			std::cout << b[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Testing assignment operator ===" << std::endl;
		Array<int> c;
		c = a;

		std::cout << "Content of array c: ";
		for (size_t i = 0; i < c.size(); ++i)
			std::cout << c[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Testing out-of-bounds access ===" << std::endl;
		std::cout << a[10] << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
