/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:43:29 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/04/28 12:51:27 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <sstream>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:
	void print();
	void print_inline(int i);
	Contact();
	Contact(std::string _first_name, std::string _last_name, std::string _nick_name, std::string _phone_number, std::string _darkest_secret);
	~Contact();
};

#endif
