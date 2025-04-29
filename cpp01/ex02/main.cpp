/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:54 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/29 12:11:57 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main() {
	std::string phrase = "HI THIS IS BRAIN";
	std::cout << "\033[1;32mString variable initialized to ''\033[0m" << phrase << "\033[1;32m''\033[0m" << std::endl << std::endl;

	std::string *stringPTR = &phrase; // pointer to string
	std::string &stringREF = phrase; // ref to string

	std::cout << "\033[1;34mMemory address of the string variable : \033[0m" << &phrase << std::endl;
	std::cout << "\033[1;34mMemory address held by stringPTR : \033[0m" << stringPTR << std::endl;
	std::cout << "\033[1;34mMemory address held by stringREF : \033[0m" << &stringREF << std::endl << std::endl;

	std::cout << "\033[1;33mValue of the string variable : \033[0m" << phrase << std::endl;
	std::cout << "\033[1;33mThe value pointed to by stringPTR : \033[0m" << *stringPTR << std::endl;
	std::cout << "\033[1;33mThe value pointed to by stringREF : \033[0m" << stringREF << std::endl;
}
