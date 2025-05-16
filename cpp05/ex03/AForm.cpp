/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:26:29 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 13:18:39 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::beSigned(Bureaucrat &obj) {
	if (sign_grade >= obj.getGrade()) {
		signature = true;
	}
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSignature() const {
	return signature;
}

size_t AForm::getSignGrade() const {
	return sign_grade;
}

size_t AForm::getExecGrade() const {
	return exec_grade;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *AForm::FormUnsignedExeption::what() const throw() {
	return "Form isnt signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
	out << obj.getName() << " AForm, signature status: " << obj.getSignature() << ", sign grade: " << obj.getSignGrade() << ", execution grade: " << obj.getExecGrade();
	return out;
}

AForm::AForm(const std::string _name, const size_t _sign_grade, const size_t _exec_grade) : name(_name), sign_grade(_sign_grade), exec_grade(_exec_grade) {
	signature = false;
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), signature(other.signature),sign_grade(other.sign_grade), exec_grade(other.exec_grade) {
}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other) {
		signature = other.getSignature();
	}
	return *this;
}

AForm::~AForm() {

}
