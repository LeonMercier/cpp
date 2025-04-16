/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:24:11 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/16 17:22:15 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	try {
		Data* one = new Data;
		one->name = "Test name";
		one->value = 42;

		std::cout << "Address: " << one << std::endl;
		uintptr_t location = Serializer::serialize(one);
		std::cout << "Address: " << "0x" << std::hex << location 
			<< std::dec << std::endl;
		Data *result = Serializer::deserialize(location);
		std::cout << "Address: " << result << std::endl;
		if (one == result) {
			std::cout << "Success" << std::endl;
		} else {
			std::cout << "Failure" << std::endl;
		}
		std::cout << result->name << ": " << result->value << std::endl;
		delete one;
	} catch (...) {
		std::cout << "Error: unhandled exception" << std::endl;
	}
}
