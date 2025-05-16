/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:01:54 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/15 13:24:28 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUBBERYCREATIONFORM_HPP
#define SCHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
};

bool duplicateFile(const std::string& sourcePath, const std::string& destinationPath);

#endif
