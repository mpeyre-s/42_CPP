/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 13:18:02 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void Bureaucrat::signForm(AForm &obj) {
	try {
		obj.beSigned(*this);
		std::cout << name << " signed " << obj.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e) {
		std::cerr << name << " couldn't sign " << obj.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e) {
		std::cerr << name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch(const AForm::FormUnsignedExeption& e) {
		std::cerr << name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
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

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}
