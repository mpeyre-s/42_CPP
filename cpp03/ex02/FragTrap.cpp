/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:18:46 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 16:29:36 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " is requesting a positive high five!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (hit_points == 0) {
		std::cout << "FragTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}

	if (energy_points >= 1) {
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
		return ;
	}

	std::cout << "FragTrap " << name << " cannot attack " << target << " beacause of no enough energy points : " << energy_points << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "FragTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}

	std::cout << "FragTrap " << name << " takes " << amount << " points of damage!" << std::endl;

	hit_points -= amount;
	if (hit_points <= 0) {
		hit_points = 0;
		std::cout << "FragTrap " << name << " is dead while fighting... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "FragTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
	}

	if (energy_points >= 1) {
		std::cout << "FragTrap " << name << " is repaired for " << amount << " points!" << std::endl;
		energy_points--;
		hit_points += amount;
		return ;
	}

	std::cout << "FragTrap " << name << " cannot be repaired beacause of no enough energy points : " << energy_points << std::endl;
}

FragTrap::FragTrap(std::string _name) {
	std::cout << "FragTrap constructor called for " << _name << std::endl;
	name = _name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &old_obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->name = old_obj.getName();
	this->hit_points = old_obj.getHitPoints();
	this->energy_points = old_obj.getEnergyPoints();
	this->attack_damage = old_obj.getAttackDamage();
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		name = obj.getName();
		hit_points = obj.getHitPoints();
		energy_points = obj.getEnergyPoints();
		attack_damage = obj.getAttackDamage();
	}
	return *this;
}

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << name << std::endl;
}
