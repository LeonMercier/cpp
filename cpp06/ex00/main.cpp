/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:19:45 by lemercie          #+#    #+#             */
/*   Updated: 2025/04/21 16:52:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main (int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else {
		std::cout << "Please give exactly one argument" << std::endl;
	}
}
