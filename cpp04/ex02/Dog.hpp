/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:30:43 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 14:50:45 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *brain;
public:
	Dog();
	Dog(std::string _type);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual void makeSound() const;
};

#endif
