/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:11:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/26 15:02:51 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
	int		nb_contact;
public:
	void add_contact(std::string _first_name, std::string _last_name, std::string _nick_name, std::string _phone_number, std::string _darkest_secret);
	void display_phonebook();
	void display_contact(int index);
	int  get_nb_contact();
	PhoneBook(); // constructor
	~PhoneBook(); // destructor
};

#endif
