/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:19:35 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 15:17:10 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n--- Array of Animals Test ---" << std::endl;

	const int arraySize = 10;
	Animal* animalArray[arraySize];

	for (int i = 0; i < arraySize; i++) {
		if (i < arraySize / 2)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();

		std::cout << "Created " << animalArray[i]->getType() << " at index " << i << std::endl;
	}

	std::cout << "\nCleaning up animal array..." << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "Deleting " << animalArray[i]->getType() << " at index " << i << std::endl;
		delete animalArray[i];
	}

	return 0;
}
