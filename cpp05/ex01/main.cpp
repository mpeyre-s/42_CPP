/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:27 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/13 14:19:39 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		std::cout << "\n----- Creating Bureaucrats -----" << std::endl;
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		std::cout << boss << std::endl;
		std::cout << intern << std::endl;

		std::cout << "\n----- Creating Forms -----" << std::endl;
		Form taxForm("Tax Form", 50, 25);
		Form secretForm("Secret Form", 5, 3);

		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		std::cout << "\n----- Signing Forms -----" << std::endl;
		boss.signForm(secretForm);
		boss.signForm(taxForm);
		intern.signForm(taxForm);

		std::cout << "\n----- Signature Status -----" << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		std::cout << "\n----- Invalid Form Tests -----" << std::endl;
		Form invalidHigh("Invalid High", 0, 20);
		// Form invalidLow("Invalid Low", 5, 151);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}
	return 0;
}
