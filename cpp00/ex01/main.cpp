/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:45:31 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/13 17:50:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>

std::string get_input(std::string prompt)
{
	std::string retval;

	std::cout << prompt;
	std::getline(std::cin, retval);
	return (retval);
}

int	main(void)
{
	PhoneBook	phone_book = PhoneBook();
	std::string	command;

	while (std::cin.eof() == false)
	{
		command = get_input("Enter command (ADD, SEARCH OR EXIT): ");
		if (command.compare("EXIT") == 0)
			return (0);
		else if (command.compare("ADD") == 0)
			phone_book.add_contact();
		else if (command.compare("SEARCH") == 0)
		{
			phone_book.print_list();
			command = get_input("Enter index: ");
			phone_book.search_contact(command);
		}
	}
}
