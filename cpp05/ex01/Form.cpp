/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:26:29 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/13 14:13:11 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::beSigned(Bureaucrat &obj) {
	if (sign_grade >= obj.getGrade()) {
		signature = true;
		std::cout << obj.getName() << " signed " << name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::string Form::getName() const {
	return name;
}

bool Form::getSignature() const {
	return signature;
}

size_t Form::getSignGrade() const {
	return sign_grade;
}

size_t Form::getExecGrade() const {
	return exec_grade;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
	out << obj.getName() << " form, signature status: " << obj.getSignature() << ", sign grade: " << obj.getSignGrade() << ", execution grade: " << obj.getExecGrade();
	return out;
}

Form::Form(const std::string _name, const size_t _sign_grade, const size_t _exec_grade) : name(_name), sign_grade(_sign_grade), exec_grade(_exec_grade) {
	signature = false;
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), signature(other.signature),sign_grade(other.sign_grade), exec_grade(other.exec_grade) {
}

Form& Form::operator=(const Form &other) {
	if (this != &other) {
		signature = other.getSignature();
	}
	return *this;
}

Form::~Form() {

}
