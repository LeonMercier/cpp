/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:43:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/17 16:50:10 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*string_ptr = &str;
	std::string	&string_ref = str;

	std::cout << &str << std::endl;
	std::cout << string_ptr << std::endl;
	std::cout << &string_ref << std::endl;

	std::cout << str << std::endl;
	std::cout << *string_ptr << std::endl;
	std::cout << string_ref << std::endl;
}
