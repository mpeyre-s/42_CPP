/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:43:01 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 16:07:02 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (hit_points == 0) {
		std::cout << "ScavTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}

	if (energy_points >= 1) {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
		return ;
	}

	std::cout << "ScavTrap " << name << " cannot attack " << target << " beacause of no enough energy points : " << energy_points << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "ScavTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << name << " takes " << amount << " points of damage!" << std::endl;

	hit_points -= amount;
	if (hit_points <= 0) {
		hit_points = 0;
		std::cout << "ScavTrap " << name << " is dead while fighting... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "ScavTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
	}

	if (energy_points >= 1) {
		std::cout << "ScavTrap " << name << " is repaired for " << amount << " points!" << std::endl;
		energy_points--;
		hit_points += amount;
		return ;
	}

	std::cout << "ScavTrap " << name << " cannot be repaired beacause of no enough energy points : " << energy_points << std::endl;
}

ScavTrap::ScavTrap(std::string _name) {
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
	name = _name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &old_obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->name = old_obj.getName();
	this->hit_points = old_obj.getHitPoints();
	this->energy_points = old_obj.getEnergyPoints();
	this->attack_damage = old_obj.getAttackDamage();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		name = obj.getName();
		hit_points = obj.getHitPoints();
		energy_points = obj.getEnergyPoints();
		attack_damage = obj.getAttackDamage();
	}
	return *this;
}

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}
