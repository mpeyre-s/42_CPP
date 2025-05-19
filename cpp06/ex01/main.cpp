/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:49:59 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/19 14:17:27 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data *data = new Data;
	uintptr_t int_addr;

	std::cout << "Adress Data ptr : " << data << std::endl;

	int_addr = Serializer::serialize(data);
	std::cout << "Adress converted to int : " << int_addr << std::endl;

	data = Serializer::deserialize(int_addr);
	std::cout << "Undo conversion ptr address : " << data << std::endl;

	delete data;
	return 0;
}
