/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:27 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 11:02:06 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	// AForm abstract; <= Uninstanciable bc of abstract class
	try {
		Bureaucrat president("President", 1);
		Bureaucrat assistant("Assistant", 70);
		Bureaucrat intern("Intern", 140);

		PresidentialPardonForm pardon("criminal");
		RobotomyRequestForm robotomy("target");
		ShrubberyCreationForm shrub("garden");

		std::cout << "\n=== Testing Presidential Pardon Form ===\n";
		std::cout << pardon << std::endl;
		intern.signForm(pardon); // fail
		intern.executeForm(pardon); // fail
		assistant.signForm(pardon); // fail
		assistant.executeForm(pardon); // fail
		president.signForm(pardon); // succes
		president.executeForm(pardon); // succes

		std::cout << "\n=== Testing Robotomy Request Form ===\n";
		std::cout << robotomy << std::endl;
		intern.signForm(robotomy); // fail
		assistant.signForm(robotomy); // succes
		assistant.executeForm(robotomy); // fail
		president.executeForm(robotomy); // succes

		std::cout << "\n=== Testing Shrubbery Creation Form ===\n";
		std::cout << shrub << std::endl;
		intern.signForm(shrub); // succes
		intern.executeForm(shrub); // fail
		assistant.executeForm(shrub); // succes

	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
