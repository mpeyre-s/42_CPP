/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:14:25 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/28 12:59:04 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int ft_stoi(const std::string &str) {
	int i;
	std::istringstream(str) >> i;
	return i;
}

static bool is_num_string(const std::string &str) {
	bool all_digits = true;
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			all_digits = false;
		}
	}
	return all_digits;
}

void	register_contact(PhoneBook &phone_book) {
	std::string first_name;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	for (size_t i = 0; i < first_name.length(); ++i) {
		if (first_name[i] == '\t')
			first_name[i] = ' ';
	}

	std::string last_name;
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	for (size_t i = 0; i < last_name.length(); ++i) {
		if (last_name[i] == '\t')
			last_name[i] = ' ';
	}

	std::string nickname;
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	for (size_t i = 0; i < nickname.length(); ++i) {
		if (nickname[i] == '\t')
			nickname[i] = ' ';
	}

	std::string phone_number;
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	for (size_t i = 0; i < phone_number.length(); ++i) {
		if (phone_number[i] == '\t')
			phone_number[i] = ' ';
	}

	std::string darkest_secret;
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	for (size_t i = 0; i < darkest_secret.length(); ++i) {
		if (darkest_secret[i] == '\t')
			darkest_secret[i] = ' ';
	}

	if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty()) {
		std::cout << "\033[31m❌ Error: one or more empty fields\033[0m" << std::endl;
		std::cout << "🏠 Back to main menu" << std::endl;
		return ;
	}

	if (is_num_string(phone_number) == false)
	{
		std::cout << "\033[31m❌ Error: not a phone number\033[0m" << std::endl;
		std::cout << "🏠 Back to main menu" << std::endl;
		return ;
	}

	phone_book.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);

	std::cout << "\033[32m✅ New contact registered\033[0m" << std::endl;
}

void search_contact(PhoneBook &phone_book) {
	phone_book.display_phonebook();

	int nb_contact = phone_book.get_nb_contact();

	if (nb_contact != 0) {
		std::string s_index_requested;
		std::cout << "Enter contact index: ";
		std::getline(std::cin, s_index_requested);

		if (s_index_requested.length() != 1 || is_num_string(s_index_requested) == false)
		{
			std::cout << "\033[31m❌ Error: contact index must exist (between 0 and 7)\033[0m" << std::endl;
			std::cout << "🏠 Back to main menu" << std::endl;
			return ;
		}
		int index_requested = ft_stoi(s_index_requested);
		if (index_requested >= 0 && index_requested <= 7 && index_requested < nb_contact)
			phone_book.display_contact(index_requested);
		else
		{
			std::cout << "\033[31m❌ Error: contact index must be existing\033[0m" << std::endl;
			std::cout << "🏠 Back to main menu" << std::endl;
		}
	}
}

void exit_program(int signum) {
	std::cout << std::endl << "Exiting program… 👋" << std::endl;
	std::exit(signum);
}
int	main() {
	PhoneBook phone_book;

	std::cout << "\033[38;5;39m---------------------------------------------" << std::endl;
	std::cout << "\033[38;5;33m|        ☎️  \033[1;4mMy Awesome PhoneBook\033[0m\033[38;5;33m ☎️          |" << std::endl;
	std::cout << "\033[38;5;63m---------------------------------------------\033[0m" << std::endl;

	while (true) {
		std::cout << "Commands available : ADD, SEARCH and EXIT" << std::endl;
		std::cout << "➡️  ";

		std::string command;
		std::getline(std::cin, command);

		if (command == "ADD")
			register_contact(phone_book);
		else if (command == "SEARCH")
			search_contact(phone_book);
		else if (command == "EXIT")
			exit_program(EXIT_SUCCESS);
	}
	return 0;
}
