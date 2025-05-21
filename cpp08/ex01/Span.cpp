/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:10:35 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/21 15:18:10 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int Span::shortestSpan() const {
	if (len < 2)
		throw SpanEmptyException();

	std::vector<int> sorted = array;
	std::sort(sorted.begin(), sorted.end());

	int result = INT_MAX;
	for (size_t i = 1; i < current; ++i) {
		int span = sorted[i] - sorted[i - 1];
		result = std::min(result, span);
	}

	return result;
}

int Span::longestSpan() const {
	if (len < 2)
		throw SpanEmptyException();

	std::vector<int> sorted = array;
	std::sort(sorted.begin(), sorted.end());

	return sorted[sorted.size() - 1] - sorted[0];
}

void Span::addNumber(int nb) {
	if (current == len)
		throw SpanFullExeption();
	array.push_back(nb);
	current++;
}

void Span::addNumberRange(int start, int end) {
	if (current == len)
		throw SpanFullExeption();
	for (int i = start; i < end; i++) {
		array.push_back(i);
		current++;
	}
}

Span::Span(size_t N) {
	len = N;
	current = 0;
}

Span::Span(const Span &other) {
	len = other.len;
	current = other.current;
	array = other.array;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		len = other.len;
		current = other.current;
		array = other.array;
	}
	return *this;
}

Span::~Span() {}

