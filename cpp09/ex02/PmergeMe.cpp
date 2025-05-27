/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:05:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/27 11:47:30 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::sortVector(std::vector<int> &vector, size_t n) {
	if (n <= 1)
		return;

	size_t middle = n / 2;
	std::vector<int> left(vector.begin(), vector.begin() + middle);
	std::vector<int> right(vector.begin() + middle, vector.end());

	sortVector(left, left.size());
	sortVector(right, right.size());

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j])
			vector[k++] = left[i++];
		else
			vector[k++] = right[j++];
	}

	while (i < left.size())
		vector[k++] = left[i++];

	while (j < right.size())
		vector[k++] = right[j++];
}

void PmergeMe::sortDeque(std::deque<int> &deque, size_t n) {
	if (n <= 1)
		return;

	size_t middle = n / 2;
	std::deque<int> left(deque.begin(), deque.begin() + middle);
	std::deque<int> right(deque.begin() + middle, deque.end());

	sortDeque(left, left.size());
	sortDeque(right, right.size());

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j])
			deque[k++] = left[i++];
		else
			deque[k++] = right[j++];
	}

	while (i < left.size())
		deque[k++] = left[i++];

	while (j < right.size())
		deque[k++] = right[j++];
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}
