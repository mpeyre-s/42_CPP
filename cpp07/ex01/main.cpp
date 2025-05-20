/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:46:07 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 10:59:01 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

template <typename T>
void printElement(T &element) {
	std::cout << element << " ";
}

template <typename T>
void doubleValue(T &element) {
	element *= 2;
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intLen, doubleValue<int>);

	std::cout << "After doubling: ";
	iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::string strArray[] = {"Hello", "World", "42"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array: ";
	iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd'};
	size_t charLen = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Char array: ";
	iter(charArray, charLen, printElement<char>);
	std::cout << std::endl;

	return 0;
}
