/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:19:35 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/10 11:40:11 by mathispeyre      ###   ########.fr       */
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

	std::cout << "\n--- Deep Copy Test ---" << std::endl;

	std::cout << "Testing Dog deep copy with copy constructor:" << std::endl;
	Dog* originalDog = new Dog();
	Dog* copiedDog = new Dog(*originalDog);

	std::cout << "Original Dog type: " << originalDog->getType() << std::endl;
	std::cout << "Copied Dog type: " << copiedDog->getType() << std::endl;

	delete originalDog;
	std::cout << "Original dog deleted, copied dog still accessible: " << copiedDog->getType() << std::endl;
	delete copiedDog;

	std::cout << "\nTesting Cat deep copy with assignment operator:" << std::endl;
	Cat* originalCat = new Cat();
	Cat* assignedCat = new Cat();
	*assignedCat = *originalCat;

	std::cout << "Original Cat type: " << originalCat->getType() << std::endl;
	std::cout << "Assigned Cat type: " << assignedCat->getType() << std::endl;

	delete originalCat;
	std::cout << "Original cat deleted, assigned cat still accessible: " << assignedCat->getType() << std::endl;
	delete assignedCat;

	return 0;
}
