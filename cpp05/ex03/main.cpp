/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:27 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 13:21:02 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Intern someRandomIntern;

		AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "garden");
		AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* presidentialForm = someRandomIntern.makeForm("presidential pardon", "John Doe");

		if (!shrubberyForm || !robotomyForm || !presidentialForm) {
			std::cout << "Form creation failed" << std::endl;
			return 1;
		}

		Bureaucrat manager("Manager", 100);
		Bureaucrat servicehead("Service Head", 35);
		Bureaucrat president("President", 1);

		std::cout << "\n--- Manager with Shrubbery Form ---" << std::endl;
		manager.signForm(*shrubberyForm); // succes
		manager.executeForm(*shrubberyForm); // succes

		std::cout << "\n--- Service Head with Robotomy Form ---" << std::endl;
		servicehead.signForm(*robotomyForm); // succes
		servicehead.executeForm(*robotomyForm); // succes

		std::cout << "\n--- President with Presidential Pardon Form ---" << std::endl;
		president.signForm(*presidentialForm); // succes
		president.executeForm(*presidentialForm); // succes

		std::cout << "\n--- Testing Invalid Form ---" << std::endl; // force intern to do shit things
		AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Test");
		if (invalidForm) {
			delete invalidForm;
		}

		delete shrubberyForm;
		delete robotomyForm;
		delete presidentialForm;

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
