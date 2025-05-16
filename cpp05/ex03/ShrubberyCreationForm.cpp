/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:04:52 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 11:00:16 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), target("Jordan") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) : AForm("ShrubberyCreation", 145, 137), target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getSignature() == true && executor.getGrade() <= getExecGrade()) {
		std::string sourceFile = "shrubbery";
		std::string destinationFile = target + "_shrubbery";
		duplicateFile(sourceFile, destinationFile);
	} else if (getSignature() == false)
		throw FormUnsignedExeption();
	else if (getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
}

bool duplicateFile(const std::string& sourcePath, const std::string& destinationPath) {
	std::ifstream sourceFile(sourcePath.c_str(), std::ios::binary);
	if (!sourceFile) {
		std::cerr << "Error: Src file unopenable" << std::endl;
		return false;
	}

	std::ofstream destinationFile(destinationPath.c_str(), std::ios::binary);
	if (!destinationFile) {
		std::cerr << "Error: Dest file uncreable" << std::endl;
		sourceFile.close();
		return false;
	}

	destinationFile << sourceFile.rdbuf();

	sourceFile.close();
	destinationFile.close();

	return true;
}
