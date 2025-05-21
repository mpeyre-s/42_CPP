/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:28 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/21 15:20:45 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	std::cout << "==== Subject Tests ====" << std::endl;
	try {
		Span span = Span(5);
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "==== Extreme Tests ====" << std::endl;
	try {
		Span extreme = Span(15000);
		extreme.addNumberRange(0, 15000);
		std::cout << "Shortest Span: " << extreme.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << extreme.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "==== Error Handling Tests ====" << std::endl;
	try {
		Span error = Span(1);
		error.addNumber(6);
		std::cout << "Shortest Span: " << error.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << error.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Span overflow = Span(2);
		overflow.addNumber(6);
		overflow.addNumber(6);
		overflow.addNumber(6);
		std::cout << "Shortest Span: " << overflow.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << overflow.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
