/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:39:26 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/26 20:19:54 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_contact(std::string _first_name, std::string _last_name, std::string _nick_name, std::string _phone_number, std::string _darkest_secret) {
	contacts[index] = Contact(_first_name, _last_name, _nick_name, _phone_number, _darkest_secret);
	index = (index + 1) % 8;
	if (nb_contact < 8)
		nb_contact++;
}

void PhoneBook::display_phonebook() {
	if (nb_contact != 0) {
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|     index|  1st name| last name|  nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 0; i < nb_contact; i++)
			contacts[i].print_inline(i);
		std::cout << "---------------------------------------------" << std::endl;
	}
}

void PhoneBook::display_contact(int index_requested) {
	contacts[index_requested].print();
	std::cout << "🏠 Back to main menu" << std::endl;
}

int PhoneBook::get_nb_contact() {
	return (nb_contact);
}

PhoneBook::PhoneBook() {
	index = 0;
	nb_contact = 0;
}

PhoneBook::~PhoneBook() {
	// destructor by default
}
