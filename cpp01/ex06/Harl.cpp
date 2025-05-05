/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:33:41 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/05 12:48:23 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "\033[33m[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
	std::cout << "\033[0m";
}

void Harl::info(void) {
	std::cout << "\033[32m[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
	std::cout << "\033[0m";
}

void Harl::warning(void) {
	std::cout << "\033[38;5;208m[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
	std::cout << "\033[0m";
}

void Harl::error(void) {
	std::cout << "\033[31m[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
	std::cout << "\033[0m";
}

void	Harl::complain(std::string level) {
	void (Harl::*pointer_to_member[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string level_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int current_level;

	for (int i = 0; i < 4; i++) {
		if (level == level_list[i])
			current_level = i;
	}

	switch (current_level) {
		case 0:
			(this->*pointer_to_member[0])();
		case 1:
			(this->*pointer_to_member[1])();
		case 2:
			(this->*pointer_to_member[2])();
		case 3:
			(this->*pointer_to_member[3])();
	}
}

Harl::Harl() {

}

Harl::~Harl() {

}
