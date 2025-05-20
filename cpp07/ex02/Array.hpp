/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:11:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/20 12:03:05 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array {
private:
	T *content;
	size_t len;
public:
	Array();
	Array(size_t);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	size_t size() const;
	T& operator[](size_t index);

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Index is out of bounds";
		}
	};
};

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= len)
		throw OutOfBoundsException();
	return content[index];
}

template <typename T>
size_t Array<T>::size() const {
	return len;
}

template <typename T>
Array<T>::Array(size_t n) {
	content = new T[n];
	len = n;
	for (size_t i = 0; i < n; ++i) {
		content[i] = T();
	}
}

template <typename T>
Array<T>::Array() {
	content = new T[0];
	len = 0;
}

template <typename T>
Array<T>::Array(const Array &other) {
	this->len = other.len;
	content = new T[len];
	for (size_t i = 0; i < len; i++) {
		content[i] = other.content[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] content;
		len = other.len;
		content = new T[len];
		for (size_t i = 0; i < len; i++) {
			content[i] = other.content[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] content;
}

