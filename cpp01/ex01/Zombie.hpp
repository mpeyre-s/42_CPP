/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:41:07 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/28 17:36:50 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string _name);
	Zombie();
	~Zombie();

	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
