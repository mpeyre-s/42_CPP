/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:08:08 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/15 12:04:30 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
};

#endif
