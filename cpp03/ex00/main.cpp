/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:07:22 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 15:09:00 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout << "\n--- Init ---\n";
	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2("FR4G-TP");

	std::cout << "\n--- Attack Tests ---\n";
	clap1.attack("Skag");
	clap1.attack("Bandit");

	std::cout << "\n--- Damage Tests ---\n";
	clap1.takeDamage(3);
	clap1.takeDamage(5);

	std::cout << "\n--- Repair Test ---\n";
	clap1.beRepaired(4);
	clap1.beRepaired(2);

	std::cout << "\n--- Energy Depletion Tests ---\n";
	for (int i = 0; i < 10; i++) {
		std::cout << "Action " << i+1 << ": ";
		clap2.attack("Gustave");
	}
	clap2.attack("Gustave");
	clap2.beRepaired(5);

	std::cout << "\n--- Death Scenario ---\n";
	ClapTrap clap3("Weak-TP");
	clap3.takeDamage(10);
	clap3.attack("Peintresse");
	clap3.beRepaired(5);

	std::cout << "\n--- Destruct ---\n";

	return 0;
}
