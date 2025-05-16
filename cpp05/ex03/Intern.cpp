/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:03:44 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 13:19:50 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::makeForm(std::string requested_form, std::string target) {
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *forms_list[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	AForm *result;

	bool found_flag = false;

	for (int i = 0; i < 3; ++i)
	{
		if (requested_form == form_names[i]) {
			std::cout << "Intern has created " << requested_form << std::endl;
			found_flag = true;
			result = forms_list[i];
		}
		else
			delete forms_list[i];
	}

	if (found_flag == false) {
		std::cout << "Error: intern did some shit" << std::endl;
		return NULL;
	}

	return result;
}

Intern::Intern() {}

Intern::Intern(const Intern &obj) {
	(void)obj;
}

Intern& Intern::operator=(const Intern &obj) {
	(void)obj;
	return *this;
}

Intern::~Intern() {}
