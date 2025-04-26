/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:14:25 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/26 17:29:30 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	register_contact(PhoneBook &phone_book) {
	std::string first_name;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::replace(first_name.begin(), first_name.end(), '\t', ' ');

	std::string last_name;
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::replace(last_name.begin(), last_name.end(), '\t', ' ');

	std::string nickname;
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::replace(nickname.begin(), nickname.end(), '\t', ' ');

	std::string phone_number;
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	std::replace(phone_number.begin(), phone_number.end(), '\t', ' ');

	std::string darkest_secret;
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	std::replace(darkest_secret.begin(), darkest_secret.end(), '\t', ' ');

	if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty()) {
		std::cout << "\033[31m❌ Error: one or more empty fields\033[0m" << std::endl;
		std::cout << "🏠 Back to main menu" << std::endl;
		return ;
	}

	if (std::all_of(phone_number.begin(), phone_number.end(), ::isdigit) == false)
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

		if (s_index_requested.length() != 1 || std::all_of(s_index_requested.begin(), s_index_requested.end(), ::isdigit) == false)
		{
			std::cout << "\033[31m❌ Error: contact index must exist (between 0 and 7)\033[0m" << std::endl;
			std::cout << "🏠 Back to main menu" << std::endl;
			return ;
		}
		int index_requested = std::stoi(s_index_requested);
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

	std::signal(SIGINT, exit_program);

	std::cout << "\033[38;5;39m---------------------------------------------" << std::endl;
	std::cout << "\033[38;5;33m|        ☎️  \033[1;4mMy Awesome PhoneBook\033[0m\033[38;5;33m ☎️          |" << std::endl;
	std::cout << "\033[38;5;63m---------------------------------------------\033[0m" << std::endl;

	while (true) {
		std::cout << "➡️  ";

		std::string command;
		std::getline(std::cin, command);

		if (command == "ADD")
			register_contact(phone_book);
		else if (command == "SEARCH")
			search_contact(phone_book);
		else if (command == "EXIT")
			exit_program(EXIT_SUCCESS);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return 0;
}
