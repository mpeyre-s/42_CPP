/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:24:25 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/19 15:34:15 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void) {
	int i = std::rand() % 3;

	switch (i) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return (NULL);
}

void identify(Base *p) {
	std::cout << "Class identified as: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow" << std::endl;
}

void identify(Base &p) {
	std::cout << "Class identified as: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (...) {}
}

int main() {
	std::srand(std::time(0));

	std::cout << "==== Identifying with pointers ====" << std::endl;
	for (int i = 0; i < 5; ++i) {
		Base* base = generate();
		identify(base);
		delete base;
	}

	std::cout << std::endl << "==== Identifying with references ====" << std::endl;
	for (int i = 0; i < 5; ++i) {
		Base* base = generate();
		identify(*base);
		delete base;
	}

	return 0;
}
