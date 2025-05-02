/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:40:05 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/02 13:40:38 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	if (ac == 4) {
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];

		std::ifstream inputFile(filename.c_str());
		if (!inputFile) {
			std::cerr << "Error : file unopenable" << filename << std::endl;
			return 1;
		}

		std::ofstream resultFile(("sed_" + filename).c_str());
		if (!resultFile) {
			std::cerr << "Erorr : temp file not created" << std::endl;
			return 1;
		}

		std::string line;
		while (std::getline(inputFile, line)) {
			size_t i = line.find(s1);
			while (i != std::string::npos) {
				line.erase(i, s1.length());
				line.insert(i, s2);
				i = line.find(s1, i + s2.length());
			}
			resultFile << line << std::endl;
		}

		inputFile.close();
		resultFile.close();
	}
	return 0;
}
