/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:28:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 11:00:02 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), target("Jordan") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("PresidentialPardon", 25, 5), target(_target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {
	return target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getSignature() == true && executor.getGrade() <= getExecGrade()) {
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	} else if (getSignature() == false)
		throw FormUnsignedExeption();
	else if (getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
}
