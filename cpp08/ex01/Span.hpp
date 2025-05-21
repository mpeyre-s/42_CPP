/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:45 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/21 16:06:27 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
private:
	std::vector<int> array;
	size_t len;
	size_t current;
public:
	Span(size_t N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int nb);
	void addNumberRange(int start, int end);
	int shortestSpan() const;
	int longestSpan() const;

	class SpanFullExeption : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Span is full";
		}
	};

	class SpanEmptyException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Span is empty or has only one element";
		}
	};
};
