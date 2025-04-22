/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:24:11 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/22 12:53:04 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data *one;
	try {
		try {
			one = new Data;
		} catch (...) {
			std::cerr << "Error: bad alloc" << std::endl;
			return 1;
		}

		one->name = "Test name";
		one->value = 42;

		std::cout << "Address: " << one << std::endl;

		uintptr_t location = Serializer::serialize(one);
		std::cout << "Address: " << "0x" << std::hex << location 
			<< std::dec << std::endl;

		Data *result = Serializer::deserialize(location);
		std::cout << "Address: " << result << std::endl;

		if (one == result) {
			std::cout << "Pointers match" << std::endl;
		} else {
			std::cout << "Pointers don't match" << std::endl;
		}

		std::cout << result->name << ": " << result->value << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete one;
}
