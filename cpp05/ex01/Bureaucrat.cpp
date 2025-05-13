/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/13 14:03:37 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(Form &obj) {
	try {
		obj.beSigned(*this);
	}
	catch(const Form::GradeTooLowException& e) {
		std::cerr << name << " couldn’t sign " << obj.getName() << " because: " << e.what() << '\n';
	}
}

std::string Bureaucrat::getName() const {
	return name;
}

size_t Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

Bureaucrat::Bureaucrat(const std::string _name, size_t _grade) : name(_name) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.getGrade();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return out;
}

Bureaucrat::Bureaucrat() {
}

Bureaucrat::~Bureaucrat() {
}
