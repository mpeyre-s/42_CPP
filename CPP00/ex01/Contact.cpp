/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:39:37 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/26 15:59:06 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::print() {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|        First Name  ||  " << first_name << std::endl;
	std::cout << "| `````````````````` || ````````````````````" << std::endl;
	std::cout << "|         Last Name  ||  " << last_name << std::endl;
	std::cout << "| `````````````````` || ````````````````````" << std::endl;
	std::cout << "|          Nickname  ||  " << nickname << std::endl;
	std::cout << "| `````````````````` || ````````````````````" << std::endl;
	std::cout << "|      Phone Number  ||  " << phone_number << std::endl;
	std::cout << "| `````````````````` || ````````````````````" << std::endl;
	std::cout << "|    Darkest Secret  ||  " << darkest_secret << std::endl;
	std::cout << "| `````````````````` || ````````````````````" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

static void	print_max_ten_chars(std::string str) {
	size_t len = str.length();
	if (len == 10)
		std::cout << str;
	else if (len < 10) {
		for (int i = 0; i < 10 - (int)len; i++)
			std::cout << " ";
		std::cout << str;
	}
	else if (len > 10) {
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	std::cout << "|";
}

void	Contact::print_inline(int i) {
	std::cout << "|         " << i << "|";
	print_max_ten_chars(first_name);
	print_max_ten_chars(last_name);
	print_max_ten_chars(nickname);
	std::cout << std::endl;
}

Contact::Contact(std::string _first_name, std::string _last_name, std::string _nick_name, std::string _phone_number, std::string _darkest_secret) {
	first_name = _first_name;
	last_name = _last_name;
	nickname = _nick_name;
	phone_number = _phone_number;
	darkest_secret = _darkest_secret;
}

Contact::Contact() {
	// constructor by default
}

Contact::~Contact() {
	// destructor by default
}
