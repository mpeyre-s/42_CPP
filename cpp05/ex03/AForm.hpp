/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:26:34 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/16 11:35:24 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool signature;
	const size_t sign_grade;
	const size_t exec_grade;

public:
	AForm();
	AForm(const std::string _name, const size_t _sign_grade, const size_t _exec_grade);
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);
	virtual ~AForm();

	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual void beSigned(Bureaucrat &obj);

	std::string getName() const;
	bool getSignature() const;
	size_t getSignGrade() const;
	size_t getExecGrade() const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	class FormUnsignedExeption : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);


#endif
