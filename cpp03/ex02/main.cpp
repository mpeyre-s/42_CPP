/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:07:22 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 16:34:27 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "\n--- CLAPTRAP TESTS ---" << std::endl;
	ClapTrap clappy("Clappy");

	clappy.attack("Enemy");
	clappy.takeDamage(5);
	clappy.beRepaired(3);
	clappy.takeDamage(10);
	clappy.attack("Nobody");

	std::cout << "\n--- SCAVTRAP TESTS ---" << std::endl;
	ScavTrap scavvy("Scavvy");

	scavvy.attack("Enemy");
	scavvy.takeDamage(20);
	scavvy.beRepaired(10);
	scavvy.guardGate();
	scavvy.takeDamage(100);
	scavvy.attack("Nobody");

	std::cout << "\n--- FRAGTRAP TESTS ---" << std::endl;
	FragTrap fraggy("Fraggy");

	fraggy.attack("Enemy");
	fraggy.takeDamage(30);
	fraggy.beRepaired(20);
	fraggy.highFivesGuys();
	fraggy.takeDamage(100);
	fraggy.attack("Nobody");

	std::cout << "\n--- DESTRUCTORS ---" << std::endl;

	return 0;
}
