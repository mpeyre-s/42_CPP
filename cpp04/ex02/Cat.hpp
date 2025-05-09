/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:12:32 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/09 14:50:21 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *brain;
public:
	Cat();
	Cat(std::string _type);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	virtual void makeSound() const;
};

#endif
