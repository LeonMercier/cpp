/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:19:45 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/21 13:49:34 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main (int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else {
/* 		double asd = std::stod("-inf");
		std::cout << asd << std::endl;
		std::cout << std::numeric_limits<int>::max() << std::endl;
		std::cout << std::numeric_limits<float>::max() << std::endl;
		std::cout << std::numeric_limits<double>::max() << std::endl; */
		std::cout << "Please give exactly one argument" << std::endl;
	}
}
