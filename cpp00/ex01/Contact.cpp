/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:45:28 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/13 19:05:22 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

std::string get_input(std::string prompt);

Contact::Contact()
{};

static std::string get_input_noempty(std::string prompt)
{
	std::string	s;

	while (true)
	{
		s = get_input(prompt);
		if (!s.empty())
			return (s);
		std::cout << "Field cannot be empty" << std::endl;
	}
}

Contact::Contact(bool ask_input)
{
	if (ask_input)
	{
		_first_name = get_input_noempty("Enter first name: ");
		_last_name = get_input_noempty("Enter last name: ");
		_nickname = get_input_noempty("Enter nickname: ");
		_phone_number = get_input_noempty("Enter phone number: ");
		_darkest_secret = get_input_noempty("What is your darkest secret? ");
	}
};

std::string	trim10(std::string s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}

void	Contact::short_print()
{
	std::cout << std::setw(10) << trim10(_first_name) << "|";
	std::cout << std::setw(10) << trim10(_last_name) << "|";
	std::cout << std::setw(10) << trim10(_nickname) << "|";
	std::cout << std::endl;
}

void	Contact::long_print()
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}
