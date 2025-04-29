/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:36:12 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/29 15:16:52 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_PP
#define	WEAPON_PP

#include <iostream>
#include <string>

class Weapon {
private:
	std::string type;
public:
	Weapon(const std::string& _type);
	Weapon();
	~Weapon();

	const std::string& getType();
	void setType(const std::string& _type);
};

#endif
