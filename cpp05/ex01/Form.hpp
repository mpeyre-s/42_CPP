/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:26:34 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/05/13 14:01:23 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool signature;
	const size_t sign_grade;
	const size_t exec_grade;

public:
	Form();
	Form(const std::string _name, const size_t _sign_grade, const size_t _exec_grade);
	Form(const Form &other);
	Form& operator=(const Form &other);
	~Form();

	void beSigned(Bureaucrat &obj);

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
};

std::ostream &operator<<(std::ostream &out, const Form &obj);


#endif
