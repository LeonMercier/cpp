/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:39:47 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/13 18:48:54 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index_to_add = 0;
	_num_contacts = 0;
}

void PhoneBook::add_contact()
{
	Contact	c = Contact(true);

	_contacts[_index_to_add] = c;
	if (_num_contacts < 8)
		_num_contacts++;
	if (_index_to_add < 7)
		_index_to_add++;
	else
		_index_to_add = 0;
}

void PhoneBook::print_list()
{
	for (int i = 0; i < _num_contacts; i++)
	{
		std::cout << "|" << std::to_string(i) << "|";
		_contacts[i].short_print();
	}
}

void PhoneBook::search_contact(std::string index)
{
	int	i = -1;
	
	try 
	{
		i = std::stoi(index);
	}
	catch (...)
	{
		std::cout << "Error: Invalid index" << std::endl;
		return ;
	}
	if (i < 0 || i > _num_contacts - 1)
	{
		std::cout << "Error: Invalid index" << std::endl;
		return ;
	}
	_contacts[i].long_print();	
}
