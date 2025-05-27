/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:04:20 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/27 12:00:49 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isValidArray(char **array, int len) {
	if (len <= 0)
		return false;

	for (int i = 0; i < len; i++) {
		if (!array[i] || array[i][0] == '\0')
			return false;

		for (int j = 0; array[i][j]; j++) {
			if (!isdigit(array[i][j]))
				return false;
		}
	}
	return true;
}

int main(int ac, char **av) {
	size_t nb_elements = (size_t)ac - 1;
	if (isValidArray(av + 1, nb_elements) == false) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		std::vector<int> vector;
		std::deque<int> deque;

		double vector_time = 0;
		double deque_time = 0;

		std::clock_t start_time;
		std::clock_t end_time;

		start_time = std::clock();
		for (size_t i = 1; i <= nb_elements; i++) {
			int value = std::atoi(av[i]);
			vector.push_back(value);
		}
		end_time = std::clock();
		vector_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

		start_time = std::clock();
		for (size_t i = 1; i <= nb_elements; i++) {
			int value = std::atoi(av[i]);
			deque.push_back(value);
		}
		end_time = std::clock();
		deque_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

		std::cout << "Before: ";
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		PmergeMe app;

		start_time = std::clock();
		app.sortVector(vector, nb_elements);
		end_time = std::clock();
		vector_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

		start_time = std::clock();
		app.sortDeque(deque, nb_elements);
		end_time = std::clock();
		deque_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

		std::cout << "After: ";
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Time to process a range of " << nb_elements << " elements with std::vector : " << vector_time << " us" << std::endl;
		std::cout << "Time to process a range of " << nb_elements << " elements with std::deque : " << deque_time << " us" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
