/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:27 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/13 11:15:29 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat jim("Jim", 150);

		std::cout << "\n--- Testing default operations ---" << std::endl;
		std::cout << bob << std::endl;
		std::cout << jim << std::endl;

		std::cout << "\n--- Testing increment/decrement ---" << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
		jim.incrementGrade();
		std::cout << jim << std::endl;

		std::cout << "\n--- Testing exceptions ---" << std::endl;
		try {
			Bureaucrat tooHigh("TooHigh", 0);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat tooLow("TooLow", 151);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try {
			bob.incrementGrade();
			std::cout << bob << std::endl;
			bob.incrementGrade();
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try {
			jim.decrementGrade();
			std::cout << jim << std::endl;
			jim.decrementGrade();
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}
