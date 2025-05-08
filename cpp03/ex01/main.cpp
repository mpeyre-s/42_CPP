/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:07:22 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 16:01:23 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "\n--- SCAVTRAP TESTS ---" << std::endl;
	ScavTrap scavvy("Scavvy");

	scavvy.attack("Enemy");
	scavvy.takeDamage(20);
	scavvy.beRepaired(10);

	scavvy.guardGate();

	std::cout << "\n--- DAMAGE LIMITS TEST ---" << std::endl;
	scavvy.takeDamage(100);
	scavvy.attack("Nobody");

	return 0;
}
