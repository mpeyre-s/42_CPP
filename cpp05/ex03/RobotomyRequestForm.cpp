/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:55:16 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 10:59:16 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), target("Jordan") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("RobotomyRequest", 72, 45), target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getSignature() == true && executor.getGrade() <= getExecGrade()) {
		std::cout << "\a\a\a\a" << std::endl;
		std::srand(time(NULL));
		int ale = std::rand();
		if (ale % 2 == 0)
			std::cout << "Nothing happened" << std::endl;
		else
			std::cout << "You were robotomized" << std::endl;
	} else if (getSignature() == false)
		throw FormUnsignedExeption();
	else if (getExecGrade() < executor.getGrade())
		throw GradeTooLowException();

}
