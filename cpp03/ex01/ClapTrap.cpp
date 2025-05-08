/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:12:09 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 15:57:42 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (hit_points == 0) {
		std::cout << "ClapTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}

	if (energy_points >= 1) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
		return ;
	}

	std::cout << "ClapTrap " << name << " cannot attack " << target << " beacause of no enough energy points : " << energy_points << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "ClapTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;

	hit_points -= amount;
	if (hit_points <= 0) {
		hit_points = 0;
		std::cout << "ClapTrap " << name << " is dead while fighting... HP : " << hit_points << " (DEAD)" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hit_points == 0) {
		std::cout << "ClapTrap " << name << " can do nothing... HP : " << hit_points << " (DEAD)" << std::endl;
	}

	if (energy_points >= 1) {
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
		energy_points--;
		hit_points += amount;
		return ;
	}

	std::cout << "ClapTrap " << name << " cannot be repaired beacause of no enough energy points : " << energy_points << std::endl;
}

std::string ClapTrap::getName(void) const {
	return name;
}

int ClapTrap::getHitPoints(void) const {
	return hit_points;
}

int ClapTrap::getEnergyPoints(void) const {
	return energy_points;
}

int ClapTrap::getAttackDamage(void) const {
	return attack_damage;
}

void ClapTrap::setName(std::string _name) {
	name = _name;
}

void ClapTrap::setHitPoints(int _hit_points) {
	hit_points = _hit_points;
}

void ClapTrap::setEnergyPoints(int _energy_points) {
	energy_points = _energy_points;
}

void ClapTrap::setAttackDamage(int _attack_damage) {
	attack_damage = _attack_damage;
}

ClapTrap::ClapTrap(std::string _name) {
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
	name = _name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ClapTrap::ClapTrap(const ClapTrap &old_obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->name = old_obj.getName();
	this->hit_points = old_obj.getHitPoints();
	this->energy_points = old_obj.getEnergyPoints();
	this->attack_damage = old_obj.getAttackDamage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		name = obj.getName();
		hit_points = obj.getHitPoints();
		energy_points = obj.getEnergyPoints();
		attack_damage = obj.getAttackDamage();
	}
	return *this;
}

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}
