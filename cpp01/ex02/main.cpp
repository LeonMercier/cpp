/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:43:53 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/06 13:14:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	// & means, type of object is reference, assignement to it doesnt need
	// special operrator
	std::string	&stringREF = str;

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	// here & means: "get address of object (doesnt matter that it is a 
	// referece"
	std::cout << &stringREF << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
