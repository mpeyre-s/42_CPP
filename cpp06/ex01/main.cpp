/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:49:59 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/19 16:23:58 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data data;
	data.nb = 42;
	data.str = "Hello World";

	std::cout << "Original pointer: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Serialized adress pointer: " << raw << std::endl;

	Data* recovered = Serializer::deserialize(raw);

	std::cout << "Recovered pointer: " << recovered << std::endl;

	if (recovered == &data)
		std::cout << "Success: The pointer was correctly serialized and deserialized." << std::endl;
	else
		std::cout << "Failure: The pointers do not match." << std::endl;
	std::cout << "Recovered data: number = " << recovered->nb << ", text = " << recovered->str << std::endl;

	return 0;
}
