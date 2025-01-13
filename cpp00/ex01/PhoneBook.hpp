/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:31:02 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/13 17:45:51 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	int		_index_to_add;
	int		_num_contacts;
	Contact	_contacts[8];
public:
	PhoneBook();
	void add_contact();
	void print_list();
	void search_contact(std::string index);
};
#endif
