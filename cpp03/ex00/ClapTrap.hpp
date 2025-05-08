/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:07:47 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/08 14:32:10 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;
public:
	ClapTrap(std::string _name);
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &old_obj);
	ClapTrap &operator=(const ClapTrap &obj);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;

	void setName(std::string _name);
	void setHitPoints(int _hit_points);
	void setEnergyPoints(int _energy_points);
	void setAttackDamage(int _attack_damage);
};

#endif
